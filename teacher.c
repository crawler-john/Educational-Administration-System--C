/*
	 关于教师的具体操作的
			函数
		作者：董笙烽
	  时间：2015/04/11
*/
#include "menu.h"
#include "teacher.h"

//定义一个链表用于存放教师数据
struct list *list_teacher = NULL;
struct list *tealogin;			//需要一个指针用来指向登陆的老师
//教师信息初始化
int init_teacher()
{	
	FILE *fp;
	struct teacher tea ;
 	//创建一个链表用于存放教师数据
	list_teacher= list_create(sizeof(struct teacher));
	if(list_teacher == NULL)
	{
		return -1;
	}
	
	//打开文件
	fp = fopen("dat/teacher.dat","r");
	if(fp == NULL)
	{
	//	printf("没有teacher.dat文件。\n");
		fp = fopen("dat/teacher.dat","w+");
		if(fp == NULL)
		{
			list_destroy(&list_teacher);
			return -1;
		}
	}
	while(1)
	{
		if(fread(&tea, sizeof(tea), 1, fp) != 1)
		{
			if(feof(fp) || ferror(fp))
			{
				break;
			}
		}
		if(list_addtail(list_teacher, &tea) == -1)
		{
			list_destroy(&list_teacher);
			fclose(fp);
			return -1;
		}
	}
	fclose(fp);
	return 0;
}
//教师登陆验证
int teacher_login()
{
	struct list *find = NULL;
	struct teacher tea;
	int trycount = 0;	
	while(trycount < 3)
	{
		show_idmenu();
		scanf("%s",tea.id);

		//现从链表中找到  name与输入name相同的管理员
		find = list_find(list_teacher,&tea, comp_id_tea);
		
		tealogin = find;
		if(find == NULL)
		{
			show_erridmenu();
		}
		else
		{
			show_passmenu();
			scanf("%s",tea.pass);
			tealogin = find;//将与输入姓名相同的管理员的位子保存到tealogin中去

		//将该结点的pass和输入的pass做比较
			if(comp_pass_tea(((struct teacher *)tealogin->dat),&tea) == 0)
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
int comp_id_tea(void *dat1, void *dat2)
{
	struct teacher *tea1 = dat1;
	struct teacher *tea2 = dat2;
	return strcmp(tea1->id,tea2->id);
}
//用于密码比较
int comp_pass_tea(void *dat1, void *dat2)
{
	struct teacher *tea1 = dat1;
	struct teacher *tea2 = dat2;
	return strcmp(tea1->pass,tea2->pass);
	
}

void print_alltea()
{
	
	CLEAR_SCREEN();
	printf("\033[33m\033[2;54H%s\033[0m","教师信息如下：\n");
	printf("\033[33m\033[4;40H%s\033[0m","教师ID\t\t教师姓名\t教师班级\n");
	list_print(list_teacher, print_teacher);
	getchar();
	getchar();
}

void print_loginteacher()
{
	CLEAR_SCREEN();
	printf("\033[33m\033[2;54H%s\033[0m","您的教师信息如下：\n");
	printf("\033[33m\033[4;40H%s\033[0m","教师ID\t\t教师姓名\t教师班级\n");
	print_teacher((struct teacher *)(tealogin)->dat);
	getchar();
	getchar();
	
}

//打印教师信息的函数
void print_teacher(void *dat)
{
	struct teacher *tea = dat;
	printf("\033[33m                                 %12s       %12s    %12s\033[0m\n",tea->id,tea->name,tea->class);
}
//添加教师的函数
void addteacher()
{
	struct teacher tea; 
	int flag;

	while(1)
	{
		flag = 0;
		struct list *find;
		CLEAR_SCREEN();
		printf("\033[33m\033[2;50H%s\033[0m","请输入以下信息");
		printf("\033[33m\033[4;50H%s\033[0m","请输入教师的ID：");
		scanf("%s",tea.id);
		find = list_find(list_teacher, &tea, comp_id_tea);
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
	printf("\033[33m\033[5;50H%s\033[0m","请输入教师的密码：");
	scanf("%s",tea.pass);
	printf("\033[33m\033[6;50H%s\033[0m","请输入教师的姓名：");
	scanf("%s",tea.name);
	printf("\033[33m\033[7;50H%s\033[0m","请输入教师的班级：");
	scanf("%s",tea.class);
	//将tea插到链表中去
	if(list_addtail(list_teacher,&tea) == 0)
	{
		printf("\033[33m\033[8;53H%s\033[0m","添加教师数据成功！\n");
		printf("\033[33m\033[9;54H%s\033[0m","请按任意键返回\n");
		getchar();
		getchar();
	}
	else
	{
		
		printf("\033[33m\033[8;50H%s\033[0m","添加教师数据失败！\n");
		printf("\033[33m\033[9;52H%s\033[0m","请按任意键返回。\n");
		getchar();
		getchar();
	}
}
//保存老师链表到文件中
int save_teacher()
{	
	FILE *fp;
	struct teacher tea;
	struct list *tmp;
	
	//打开文件
	fp = fopen("dat/teacher.dat","w");
	if(fp == NULL)
	{
		return -1;
	}
	for(tmp = list_teacher->next;tmp != list_teacher;tmp = tmp->next)
	{			//放一个数据到tea里面
		memcpy(&tea,tmp->dat,sizeof(struct teacher));
		fwrite(&tea, sizeof(tea), 1, fp);
	}
	//关闭文件
	fclose(fp);
	return 0;
}
//删除某个老师
void delteacher()
{
	struct teacher tea; 
	CLEAR_SCREEN();
	printf("\033[33m\033[2;50H%s\033[0m","删除教师界面");
	printf("\033[33m\033[4;50H%s\033[0m","请输入教师的ID：");
	scanf("%s",tea.id);
	if(list_find(list_teacher, &tea, comp_id_tea) != NULL)
	{
		list_del(list_teacher, &tea, comp_id_tea);
		printf("\033[33m\033[8;50H%s\033[0m","删除教师数据成功！\n");
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

void changeteacher()
{
	struct teacher tea;
	struct list *find;
	CLEAR_SCREEN();
	printf("\033[33m\033[2;50H%s\033[0m","修改教师界面");
	printf("\033[33m\033[4;45H%s\033[0m","请输入需要修改教师的ID：");
	scanf("%s",tea.id);
	find = list_find(list_teacher, &tea, comp_id_tea);
	if(find != NULL)
	{
		CLEAR_SCREEN();
		printf("\033[33m\033[2;50H%s\033[0m","修改教师界面");
		printf("\033[33m\033[4;50H%s\033[0m","1.修改姓名");
		scanf("%s",((struct teacher *)(find->dat))->name);
		printf("\033[33m\033[5;50H%s\033[0m","2.修改密码");
		scanf("%s",((struct teacher *)(find->dat))->pass);
		printf("\033[33m\033[6;50H%s\033[0m","3.修改班级");
		scanf("%s",((struct teacher *)(find->dat))->class);
		
				
		printf("\033[33m\033[8;50H%s\033[0m","添加老师成功！");
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

void changeteaname()
{
	CLEAR_SCREEN();
	printf("\033[33m\033[2;50H%s\033[0m","修改教师姓名界面");
	printf("\033[33m\033[4;50H%s\033[0m","修改姓名为");
	scanf("%s",((struct teacher *)(tealogin->dat))->name);	
	printf("\033[33m\033[12;50H%s\033[0m","修改学生姓名成功！");
	getchar();
	getchar();
}

void changeteapass()
{
	char pass1[20];
	char pass2[20];
	CLEAR_SCREEN();
	printf("\033[33m\033[2;50H%s\033[0m","修改教师密码界面");
	printf("\033[33m\033[4;50H%s\033[0m","输入修改密码为");
	scanf("%s",pass1);	
	printf("\033[33m\033[5;50H%s\033[0m","再次输入修改密码");
	scanf("%s",pass2);	
	if(strcmp(pass1,pass2) == 0)
	{
		memcpy(((struct teacher *)(tealogin->dat))->pass,pass1,sizeof(pass1));
		printf("\033[33m\033[12;50H%s\033[0m","修改教师密码成功！");
		getchar();
		getchar();
	}
	else
	{
		printf("\033[33m\033[12;50H%s\033[0m","修改教师密码失败！");
		getchar();
		getchar();
	}
	
}

void changeteaclass()
{
	CLEAR_SCREEN();
	printf("\033[33m\033[2;50H%s\033[0m","修改教师班级界面");
	printf("\033[33m\033[4;50H%s\033[0m","修改班级为");
	scanf("%s",((struct teacher *)(tealogin->dat))->class);	
	printf("\033[33m\033[12;50H%s\033[0m","修改学生姓名成功！");
	getchar();
	getchar();
}

void destroy_teacher(void)
{
	list_destroy(&list_teacher);
}
