/*
	 界面函数和界面操作
		的函数声明
		作者：董笙烽
	  时间：2015/04/11
*/
#ifndef __MENU_H__
#define __MENU_H__
#include <stdio.h>
//清屏操作
#define CLEAR_SCREEN() do{						\
			printf("\033[2J\033[1;1H\n");	\
	}while(0)

#define DEFAULT() do{					\
	printf("\n\t\t\t\t\t您输入的选项有错误，请按输入任意字符后重新输入！");	\
	getchar();														\
	getchar();														\
}while(0)
//主界面
void show_mainmenu();
//教师登陆界面
void show_teamenu();
//输入ID界面
void show_idmenu();
//输入密码界面
void show_passmenu();
//帐号输入错误界面
void show_erridmenu();
//密码输入错误界面
void show_errpassmenu();
//管理员登陆界面
void show_manmenu();
//管理教师界面
void show_tea_manmenu();
//管理学生界面
void show_stu_manmenu();
//删除修改退出显示界面
void show_dcqmenu();
//学生查找界面
void show_stufindmenu();
//教师查找界面
void show_teafindmenu();
//学生成绩排序界面
void show_sortmenu();
//教师信息查询界面
void show_tea_infmenu();
//学生信息查询界面
void show_stu_infmenu();
//界面操作函数
void menu_operation();
//界面学生操作
void menu_stu_operation();
//界面教师操作
void menu_tea_operation();
//学生成绩排序操作
void menu_stu_sort_operation();
//教师我信息查看界面
void menu_teainf_operation();
//学生自我信息查找修改
void menu_stuinf_operation();
#endif
