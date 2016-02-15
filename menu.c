/*
	 关于菜单具体操作的
			函数
		作者：董笙烽
	  时间：2015/04/11
*/
#include "menu.h"
#include "teacher.h"
#include "manager.h"
#include "student.h"
char *mainmenu[] = {
	"1.管理员登陆",
	"2.教师登陆",
	"3.学生登陆",
	"4.退出"
};
char *teamenu[] = {
	"1.自己的信息",
	"2.学生管理",
	"3.退出"
};
char *manmenu[] = {
	"1.教师管理",
	"2.学生管理",
	"3.退出"
};
char *stu_manmenu[] = {
	"1.显示全部学生",
	"2.添加学生",
	"3.删除学生",
	"4.修改学生",
	"5.排序学生",
	"6.退出"
};
char *tea_manmenu[] = {
	"1.显示全部教师",
	"2.添加教师",
	"3.删除教师",
	"4.修改教师",
	"5.退出"
};
char *teafindmenu[] = {
	"1.通过ID查找",
	"2.通过姓名查找",
	"3.通过班级查找",
	"4.退出"
};
char *stufindmenu[] = {
	"1.通过学号",
	"2.通过姓名",
	"3.通过班级",	
	"4.退出"
};
char *dcqmenu[] = {
	"1.删除",
	"2.修改",
	"3.退出"
};
char *sortmenu[] ={
	"1.通过学号排序",
	"2.通过平均成绩排序",
	"3.通过语文成绩排序",
	"4.通过数学成绩排序",
	"5.通过C语言成绩排序",
	"6.退出",
};
char *teainfmenu[] = {
	"1.查看信息",
	"2.修改姓名",
	"3.修改密码",
	"4.修改班级",
	"5.退出"
};
//主界面
void show_mainmenu()
{	

	int i;
	CLEAR_SCREEN();
	printf("\033[33m\033[2;50H%s\033[0m","欢迎使用学生管理系统-V2015");
	for(i = 0; i < sizeof(mainmenu) / sizeof(mainmenu[0]); i++)
	{
		printf("\033[%d;%dH%s",	i + 4, 50, mainmenu[i]);
	}
	
	printf("\033[%d;%dH请输入你的选择：",	i + 5, 50);
}
//教师登陆界面
void show_teamenu()
{
	int i;
	CLEAR_SCREEN();
	printf("\033[33m\033[2;50H%s\033[0m","欢迎使用学生管理系统");
	for(i = 0; i < sizeof(teamenu) / sizeof(teamenu[0]); i++)
	{
		printf("\033[%d;%dH%s",	i + 4, 50, teamenu[i]);
	}
	
	printf("\033[%d;%dH请输入你的选择：",	i + 5, 50);
}
//输入ID界面
void show_idmenu()
{
	CLEAR_SCREEN();
	printf("\033[33m\033[2;50H%s\033[0m","欢迎登入管理系统");
	printf("\033[%d;%dH%s",	5, 50, "请输入您的ID：");
}
//输入密码界面
void show_passmenu()
{
	
	printf("\033[%d;%dH%s",	7, 50, "请输入您的密码：");
}
//帐号输入错误界面
void show_erridmenu()
{
	printf("\033[%d;%dH%s",	11, 40, "对不起您输入的ID不存在，请按任意键后重新输入");
	getchar();
	getchar();
}
//密码输入错误界面
void show_errpassmenu()
{
	printf("\033[%d;%dH%s",	11, 40, "对不起您输入的密码错误，请按任意键后重新输入");
	getchar();
	getchar();
}
//管理员登陆界面
void show_manmenu()
{
	int i;
	CLEAR_SCREEN();
	printf("\033[33m\033[2;50H%s\033[0m","欢迎使用学生管理系统");
	for(i = 0; i < sizeof(manmenu) / sizeof(manmenu[0]); i++)
	{
		printf("\033[%d;%dH%s",	i + 4, 50, manmenu[i]);
	}
	
	printf("\033[%d;%dH请输入你的选择：",	i + 5, 50);

}
//管理教师界面
void show_tea_manmenu()
{
	int i;
	CLEAR_SCREEN();
	printf("\033[33m\033[2;60H%s\033[0m","管理教师界面");
	for(i = 0; i < sizeof(tea_manmenu) / sizeof(tea_manmenu[0]); i++)
	{
		printf("\033[%d;%dH%s",	i + 4, 50, tea_manmenu[i]);
	}
	
	printf("\033[%d;%dH请输入你的选择：",	i + 5, 50);

}
//管理学生界面
void show_stu_manmenu()
{
	int i;
	CLEAR_SCREEN();
	printf("\033[33m\033[2;60H%s\033[0m","管理学生界面");
	for(i = 0; i < sizeof(stu_manmenu) / sizeof(stu_manmenu[0]); i++)
	{
		printf("\033[%d;%dH%s",	i + 4, 50, stu_manmenu[i]);
	}
	
	printf("\033[%d;%dH请输入你的选择：",	i + 5, 50);

}
//教师查找界面
void show_teafindmenu()
{
	int i;
	CLEAR_SCREEN();
	printf("\033[33m\033[2;60H%s\033[0m","教师查找界面");
	for(i = 0; i < sizeof(teafindmenu) / sizeof(teafindmenu[0]); i++)
	{
		printf("\033[%d;%dH%s",	i + 4, 50, teafindmenu[i]);
	}
	
	printf("\033[%d;%dH请输入你的选择：",	i + 5, 50);
}

//学生查找界面
void show_stufindmenu()
{
	int i;
	CLEAR_SCREEN();
	printf("\033[33m\033[2;60H%s\033[0m","学生查找界面");
	for(i = 0; i < sizeof(stufindmenu) / sizeof(stufindmenu[0]); i++)
	{
		printf("\033[%d;%dH%s",	i + 4, 50, stufindmenu[i]);
	}
	
	printf("\033[%d;%dH请输入你的选择：",	i + 5, 50);
}
//删除修改退出显示界面
void show_dcqmenu()
{
	int i;
	CLEAR_SCREEN();
	printf("\033[33m\033[2;60H%s\033[0m","学生成绩排序界面");
	for(i = 0; i < sizeof(dcqmenu) / sizeof(dcqmenu[0]); i++)
	{
		printf("\033[%d;%dH%s",	i + 4, 50, dcqmenu[i]);
	}
	
	printf("\033[%d;%dH请输入你的选择：",	i + 5, 50);
}

//学生成绩排序界面
void show_sortmenu()
{
	int i;
	CLEAR_SCREEN();
	printf("\033[33m\033[2;60H%s\033[0m","学生成绩排序界面");
	for(i = 0; i < sizeof(sortmenu) / sizeof(sortmenu[0]); i++)
	{
		printf("\033[%d;%dH%s",	i + 4, 50, sortmenu[i]);
	}
	
	printf("\033[%d;%dH请输入你的选择：",	i + 5, 50);
}
//教师信息查询界面
void show_tea_infmenu()
{
	int i;
	CLEAR_SCREEN();
	printf("\033[33m\033[2;50H%s\033[0m","教师自我信息查找修改界面");
	for(i = 0; i < sizeof(teainfmenu) / sizeof(teainfmenu[0]); i++)
	{
		printf("\033[%d;%dH%s",	i + 4, 50, teainfmenu[i]);
	}
	
	printf("\033[%d;%dH请输入你的选择：",	i + 5, 50);
}

char *stuinfmenu[] = {
	"1.查看自己的信息",
	"2.修改姓名",
	"3.修改密码",
	"4.退出",
};
//学生信息查询界面
void show_stu_infmenu()
{
	int i;
	CLEAR_SCREEN();
	printf("\033[33m\033[2;50H%s\033[0m","学生自我信息查找修改界面");
	for(i = 0; i < sizeof(stuinfmenu) / sizeof(stuinfmenu[0]); i++)
	{
		printf("\033[%d;%dH%s",	i + 4, 50, stuinfmenu[i]);
	}
	
	printf("\033[%d;%dH请输入你的选择：",	i + 5, 50);
}

void menu_operation()
{
	int sel;
	int flag ;
	while(1)
	{
		//显示主函数菜单
		show_mainmenu();
		//读取用户的选择
		scanf("%d", &sel);
	
		switch(sel)
		{
			case 1://管理员登陆
					if (manager_login() == 0)		//调用管理员登入函数 , 返回值为0表示帐号密码匹配正确登陆成功
					{
						while(1)
						{		
							flag = 1;
							show_manmenu();
							scanf("%d", &sel);
							switch(sel)
							{
								case 1: // 教师管理	
										menu_tea_operation();
										break;
								case 2: //学生管理
										menu_stu_operation();
										break;
								case 3: //退出
										flag = 0;
										break;
								default: DEFAULT();
										break;
							}
							if(flag == 0)
							{
								break;
							}
						}
					}
					break;
			case 2://教师登陆
					if(teacher_login() == 0)
					{
						while(1)
						{	
							flag = 1;
							show_teamenu();
							scanf("%d", &sel);
							switch(sel)
							{
								case 1: //查看自己的信息
										menu_teainf_operation();
										break;
								case 2: //学生管理
										menu_stu_operation();
										break;
								case 3: //退出
										flag = 0;
										break;
								default: DEFAULT();
										break;
							}
							if(flag == 0)
							{
								break;
							}
						}
					}
					break;
			case 3://学生登入
					if(student_login() == 0)
					{
						menu_stuinf_operation();	
					}
					break;
			case 4://退出  当退出的时候需要销毁三个链表
					return;
					break;
			default: DEFAULT();
					break;
		}
	}
}
void menu_teainf_operation()
{
		int flag = 1;
		int sel;
		while(1)
		{
				show_tea_infmenu();
				scanf("%d", &sel);
				switch(sel)
				{
						case 1: //查看信息
								print_loginteacher();
								break;
						case 2: //修改姓名
								changeteaname();
								save_teacher();
								break;
						case 3: //修改密码
								changeteapass();
								save_teacher();
								break;
						case 4: //修改班级
								changeteaclass();
								save_teacher();
								break;
						case 5: //退出
								flag = 0;
								break;
						default: DEFAULT();
								 break;
				}
				if(flag == 0)
				{
						break;
				}
		}	

}
//学生自我信息查找修改
void	menu_stuinf_operation()
{
		int flag = 1;
		int sel;
		while(1)
		{
				show_stu_infmenu();
				scanf("%d", &sel);
				switch(sel)
				{
						case 1: //查看信息
								print_loginstudent();
								break;
						case 2: //修改姓名
								changestuname();
								save_student();
								break;
						case 3: //修改密码
								changestupass();
								save_student();
								break;
						case 4: //退出
								flag = 0;
								break;
						default: DEFAULT();
								 break;
				}
				if(flag == 0)
				{
					break;
				}
		}	
}
void menu_stu_operation()
{
		int flag = 1;
		int sel;
		while(1)
		{
				show_stu_manmenu();
				scanf("%d", &sel);
				switch(sel)
				{
						case 1: //显示全部学生
								print_allstu();
								break;
						case 2: //添加学生
								addstudent();
								save_student(); 
								break;
						case 3: //删除学生
								delstudent();
								save_student(); 
								break;
						case 4: //修改学生
								changestudent();
								save_student(); 
								break;
						case 5: //排序学生
								menu_stu_sort_operation();
								break;
						case 6: //退出
								flag = 0;
								break;
						default: DEFAULT();
								break;
				}
				if(flag == 0)
				{
					break;
				}
		}	
}
//学生排序操作界面
void menu_stu_sort_operation()
{
		int flag = 1;
		int sel;
		while(1)
		{
				show_sortmenu();
				scanf("%d", &sel);
				switch(sel)
				{
						case 1: //通过学号排序
								sort_student_id();
								print_allstu();
								break;
						case 2: //通过平均成绩排序
								sort_student_average();
								print_allstu();
								break;
						case 3: //通过语文成绩排序
								sort_student_chinese();
								print_allstu();
								break;
						case 4: //通过数学成绩排序
								sort_student_math();
								print_allstu();
								break;
						case 5: //通过C语言成绩排序
								sort_student_c();
								print_allstu();
								break;
						case 6: //退出
								flag = 0;
								break;
						default: DEFAULT();
								break;
				}
				if(flag == 0)
				{
					break;
				}
		}	
}
void menu_tea_operation()
{
		int flag = 1;
		int sel;
		while(1)
		{
				show_tea_manmenu();
				scanf("%d", &sel);
				switch(sel)
				{
						case 1: //显示全部老师
								print_alltea();
								break;
						case 2: //添加老师
								 addteacher();
								//将添加后的链表加到teacher.dat文件去
								save_teacher();
								break;
						case 3: //删除老师
								delteacher();
								save_teacher();
								break;
						case 4: //修改老师
								changeteacher();
								save_teacher();
							
								break;
						case 5: //退出
								flag = 0;
								break;
						default: DEFAULT();
								break;
				}
				if(flag == 0)
				{
					break;
				}

		}	
}
