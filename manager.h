/*
	 管理员结构结构体的定义
	关于管理员操作的函数声明
		作者：董笙烽
	  时间：2015/04/11
*/
#ifndef __MANAGER_H__
#define __MANAGER_H__
#include "list.h"
#include <stdio.h>
#include <string.h>
struct manager
{
	char name[20];
	char pass[20];
};
//管理员的登陆
int manager_login();
//初始化管理员数据
int init_manager();
//用于比较姓名是否相同的函数
int comp_name_man(void *dat1, void *dat2);
//用于密码比较
int comp_pass_man(void *dat1, void *dat2);
//销毁管理员链表
void destroy_manager(void);
#endif
