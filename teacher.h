/*
	 教师结构结构体的定义
	关于教师操作的函数声明
		作者：董笙烽
	  时间：2015/04/11
*/
#ifndef __TEACHER_H__
#define __TEACHER_H__

#include "list.h"

#include <stdio.h>
//定义教师结构体
struct teacher
{
	char id[20];
	char pass[20];
	char name[20];
	char class[20];
};
//教师信息初始化
int init_teacher();
//教师登入验证
int teacher_login();
//用于比较姓名是否相同的函数
int comp_id_tea(void *dat1, void *dat2);
//用于密码比较
int comp_pass_tea(void *dat1, void *dat2);
//打印所有教师的数据函数
void print_alltea();
//打印教师信息的函数
void print_teacher(void *dat);
//添加教师的函数
void addteacher();
//保存老师链表到文件中
int save_teacher();
//删除某个老师
void delteacher();
//打印当前登陆老师信息
void print_loginteacher();
//修改教师姓名
void changeteaname();
//修改教师密码
void changeteapass();
//修改教师班级
void changeteaclass();
//销毁教师链表
void destroy_teacher(void);
#endif
