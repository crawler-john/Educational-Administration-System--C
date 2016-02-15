/*
	 关于学生具体操作的
			函数
		作者：董笙烽
	  时间：2015/04/11
*/
#include "student.h"
#include "menu.h"
//定义一个存放学生数据的链表
struct list *list_student = NULL;
struct list *stulogin;  //用于保存登陆学生的位子的指针
//学生数据初始化
int init_student()
{
	FILE *fp;
	struct student stu;
	//创建链表用于存放学生的数据
	list_student = list_create(sizeof(struct student));
	if(list_student == NULL)
	{	//分配链表头结点失败
		return -1;
	}
	//读取student.dat文件，然后保存所有的数据到list_student链表里面
	fp = fopen("dat/student.dat","r");
	if(fp == NULL)
	{
	//	printf("没有student.dat文件.\n");
		fp = fopen("dat/student.dat","w+");
		if(fp == NULL)
		{
			list_destroy(&list_student);
			return -1;
		}
	}
	while(1)
	{
		if(fread(&stu, sizeof(stu), 1, fp) != 1)
		{	//读取文件结束
			if(feof(fp) || ferror(fp))
			{
				break;
			}
		}
		if(list_addtail(list_student, &stu) == -1)
		{
			list_destroy(&list_student);
			fclose(fp);
			return -1;
		}	
	}
	fclose(fp);
	return 0;
}
//登陆验证学生
int student_login()
{
	int trycount = 0;
	struct list *find = NULL;
	struct student stu;
	while(trycount < 3)
	{
		show_idmenu();
		scanf("%s",stu.id);

		//现从链表中找到  name与输入name相同的管理员
		find = list_find(list_student,&stu, comp_id_stu);
		stulogin = find;
		if(find == NULL)
		{
			show_erridmenu();
		}
		else
		{
			show_passmenu();
			scanf("%s",stu.pass);
			stulogin = find;//将与输入姓名相同的管理员的位子保存到stulogin中去

		//将该结点的pass和输入的pass做比较
			if(comp_pass_stu(((struct student *)stulogin->dat),&stu) == 0)
			{
				return 0;
			}
			else
			{
				if(trycount < 2)
				{
					show_errpassmenu();
				}
			}
		}
		trycount++;
		if(trycount == 3)
		{	
			printf("\033[33m\033[10;48H%s\033[0m","对不起您输入错误次数过多\n");
			getchar();
			getchar();
		}	
	}
}

//用于比较姓名是否相同的函数
int comp_id_stu(void *dat1, void *dat2)
{
	struct student *stu1 = dat1;
	struct student *stu2 = dat2;
	return strcmp(stu1->id,stu2->id);
}
//用于密码比较
int comp_pass_stu(void *dat1, void *dat2)
{
	struct student *stu1 = dat1;
	struct student *stu2 = dat2;
	return strcmp(stu1->pass,stu2->pass);
	
}

void print_allstu()
{
	
	CLEAR_SCREEN();
	printf("\033[33m\033[2;54H%s\033[0m","学生信息如下：\n");
	printf("\033[33m\033[4;10H%s\033[0m","学生ID\t\t学生姓名\t学生年龄\t学生班级\t语文成绩\t数学成绩\tC语言成绩\t平均成绩\n");
	list_print(list_student, print_student);
	getchar();
	getchar();
}
//打印当前学生的信息
void print_loginstudent()
{
	CLEAR_SCREEN();
	printf("\033[33m\033[2;54H%s\033[0m","您的学生信息如下：\n");
	printf("\033[33m\033[4;10H%s\033[0m","学生ID\t\t学生姓名\t学生年龄\t学生班级\t语文成绩\t数学成绩\tC语言成绩\t平均成绩\n");
	print_student(stulogin->dat);
	getchar();
	getchar();
	
}
//打印学生信息的函数
void print_student(void *dat)
{
	struct student *stu = dat;
	printf("\033[33m   %12s\t    %12s             %3d    %12s             %3d             %3d              %3d            %3d\033[0m\n",stu->id,stu->name,stu->age,stu->class,stu->grade[0],stu->grade[1],stu->grade[2],stu->average);
}
//添加学生的函数
void addstudent()
{
	struct student stu; 
	int flag;
	while(1)
	{
		flag = 0;
		CLEAR_SCREEN();
		struct list *find;
		printf("\033[33m\033[2;50H%s\033[0m","请输入以下信息");
		printf("\033[33m\033[4;50H%s\033[0m","请输入学生的ID：");
		scanf("%s",stu.id);
		find = list_find(list_student, &stu, comp_id_stu);
		if(find  != NULL)
		{
			printf("\033[33m\033[6;50H%s\033[0m","帐号已注册，请按任意键重试。\n");
			getchar();
			getchar();
		}
		else
		{
			
			flag = 1;
		}
		if(flag == 1)
		{
			break;
		}
	}
	printf("\033[33m\033[5;50H%s\033[0m","请输入学生的密码：");
	scanf("%s",stu.pass);
	printf("\033[33m\033[6;50H%s\033[0m","请输入学生的姓名：");
	scanf("%s",stu.name);
	printf("\033[33m\033[7;50H%s\033[0m","请输入学生的年龄：");
	scanf("%d",&stu.age);
	printf("\033[33m\033[8;50H%s\033[0m","请输入学生的班级：");
	scanf("%s",stu.class);
	printf("\033[33m\033[9;50H%s\033[0m","请输入学生的语文成绩：");
	scanf("%d",&stu.grade[0]);
	printf("\033[33m\033[10;50H%s\033[0m","请输入学生的数学成绩：");
	scanf("%d",&stu.grade[1]);
	printf("\033[33m\033[11;50H%s\033[0m","请输入学生的C语言成绩：");
	scanf("%d",&stu.grade[2]);
	stu.average = (stu.grade[0]+stu.grade[1]+stu.grade[2])/3;
	//将stu插到链表中去
	if(list_addtail(list_student,&stu) == 0)
	{
		printf("\033[33m\033[12;50H%s\033[0m","添加学生数据成功！\n");
		getchar();
		getchar();
	}
	else
	{
		
		printf("\033[33m\033[12;50H%s\033[0m","添加学生数据失败！\n");
		getchar();
		getchar();
	}
}

//保存学生链表到文件中
int save_student()
{	
	FILE *fp;
	struct student stu;
	struct list *tmp;
	
	//打开文件
	fp = fopen("dat/student.dat","w");
	if(fp == NULL)
	{
		return -1;
	}
	for(tmp = list_student->next;tmp != list_student;tmp = tmp->next)
	{			//放一个数据到stu里面
		memcpy(&stu,tmp->dat,sizeof(struct student));
		fwrite(&stu, sizeof(stu), 1, fp);
	}
	//关闭文件
	fclose(fp);
	return 0;
}
//删除学生
void delstudent()
{
	struct student stu; 
	CLEAR_SCREEN();
	printf("\033[33m\033[2;50H%s\033[0m","删除学生界面");
	printf("\033[33m\033[4;50H%s\033[0m","请输入学生的ID：");
	scanf("%s",stu.id);
	if(list_find(list_student, &stu, comp_id_stu) != NULL)
	{
		list_del(list_student, &stu, comp_id_stu);
		printf("\033[33m\033[8;50H%s\033[0m","删除学生数据成功！\n");
		getchar();
		getchar();
	}
	else
	{
		printf("\033[33m\033[8;50H%s\033[0m","对不起没有找到该学生！\n");
		getchar();
		getchar();
	}
	
}
//管理员或者老师修改学生数据
void changestudent()
{
	struct student stu;
	struct list *find;
	CLEAR_SCREEN();
	printf("\033[33m\033[2;50H%s\033[0m","修改学生界面");
	printf("\033[33m\033[4;45H%s\033[0m","请输入需要修改学生的ID：");
	scanf("%s",stu.id);
	find = list_find(list_student, &stu, comp_id_stu);
	if(find != NULL)
	{
		CLEAR_SCREEN();
		printf("\033[33m\033[2;50H%s\033[0m","修改学生界面");
		printf("\033[33m\033[4;50H%s\033[0m","1.修改姓名为");
		scanf("%s",((struct student *)(find->dat))->name);
		printf("\033[33m\033[5;50H%s\033[0m","2.修改密码为");
		scanf("%s",((struct student *)(find->dat))->pass);
		printf("\033[33m\033[6;50H%s\033[0m","3.修改年龄为");
		scanf("%d",&((struct student *)(find->dat))->age);
		printf("\033[33m\033[7;50H%s\033[0m","3.修改班级为");
		scanf("%s",((struct student *)(find->dat))->class);
		printf("\033[33m\033[8;50H%s\033[0m","3.修改语文成绩为");
		scanf("%d",&((struct student *)(find->dat))->grade[0]);
		printf("\033[33m\033[9;50H%s\033[0m","3.修改数学成绩为");
		scanf("%d",&((struct student *)(find->dat))->grade[1]);
		printf("\033[33m\033[10;50H%s\033[0m","3.修改C语言成绩为");
		scanf("%d",&((struct student *)(find->dat))->grade[2]);
		((struct student *)(find->dat))->average = (((struct student *)(find->dat))->grade[0]+((struct student *)(find->dat))->grade[1]+((struct student *)(find->dat))->grade[2])/3;
		printf("\033[33m\033[12;50H%s\033[0m","修改学生信息成功！");
		getchar();
		getchar();
	}
	else
	{
		printf("\033[33m\033[8;50H%s\033[0m","对不起没有找到该教师！\n");
		getchar();
		getchar();
		
	}
	
}
void changestuname()
{
	CLEAR_SCREEN();
	printf("\033[33m\033[2;50H%s\033[0m","修改学生姓名界面");
	printf("\033[33m\033[4;50H%s\033[0m","修改姓名为");
	scanf("%s",((struct student *)(stulogin->dat))->name);	
	printf("\033[33m\033[12;50H%s\033[0m","修改学生姓名成功！");
	getchar();
	getchar();
		
	
}
void changestupass()
{
	char pass1[20];
	char pass2[20];
	CLEAR_SCREEN();
	printf("\033[33m\033[2;50H%s\033[0m","修改学生密码界面");
	printf("\033[33m\033[4;50H%s\033[0m","输入修改密码为");
	scanf("%s",pass1);	
	printf("\033[33m\033[5;50H%s\033[0m","再次输入修改密码");
	scanf("%s",pass2);	
	if(strcmp(pass1,pass2) == 0)
	{
		memcpy(((struct student *)(stulogin->dat))->pass,pass1,sizeof(pass1));
		printf("\033[33m\033[12;50H%s\033[0m","修改学生密码成功！");
		getchar();
		getchar();
	}
	else
	{
		printf("\033[33m\033[12;50H%s\033[0m","修改学生密码失败！");
		getchar();
		getchar();
	}
	
}	
//通过ID排序学生
void sort_student_id()
{
	list_sort(list_student, comp_student_id);

}
//通过平均成绩排序学生
void sort_student_average()
{
	list_sort(list_student, comp_student_average);

}
//通过语文成绩排序学生
void sort_student_chinese()
{
	list_sort(list_student, comp_student_chinese);

}
//通过数学成绩排序学生
void sort_student_math()
{
	list_sort(list_student, comp_student_math);

}
//通过C语言成绩排序学生
void sort_student_c()
{
	list_sort(list_student, comp_student_c);

}

//自定义的ID比较函数
int comp_student_id(void *dat1,void *dat2)
{
	struct student *stu1 = dat1;
	struct student *stu2 = dat2;
	return strcmp(stu1->id,stu2->id);
	
}
//自定义的average比较函数
int comp_student_average(void *dat1,void *dat2)
{
	struct student *stu1 = dat1;
	struct student *stu2 = dat2;
	return (stu2->average - stu1->average);
	
}
//自定义的chinese比较函数
int comp_student_chinese(void *dat1,void *dat2)
{
	struct student *stu1 = dat1;
	struct student *stu2 = dat2;
	return (stu2->grade[0] - stu1->grade[0]);
	
}
//自定义的math比较函数
int comp_student_math(void *dat1,void *dat2)
{
	struct student *stu1 = dat1;
	struct student *stu2 = dat2;
	return (stu2->grade[1] - stu1->grade[1]);
	
}
//自定义的c比较函数
int comp_student_c(void *dat1,void *dat2)
{
	struct student *stu1 = dat1;
	struct student *stu2 = dat2;
	return (stu2->grade[2] - stu1->grade[2]);
	
}

void destroy_student(void)
{
	list_destroy(&list_student);
}
