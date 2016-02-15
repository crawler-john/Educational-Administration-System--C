/*
	 学生结构结构体的定义
	关于学生操作的函数声明
		作者：董笙烽
	  时间：2015/04/11
*/
#ifndef __STUDENT_H__
#define __STUDENT_H__
#include "list.h"
#include <stdio.h>
struct student
{
	char id[20];			//学号
	char pass[20];			//密码
	char name[20];	//姓名
	int age;		//年龄
	char class[20];	//班级
	int grade[3];	//分别存放语文 数学 C语言成绩
	int average;		//平均成绩
};

//学生数据初始化
int init_student();
//学生登入操作
int student_login();
//用于比较姓名是否相同的函数
int comp_id_stu(void *dat1, void *dat2);
//用于密码比较
int comp_pass_stu(void *dat1, void *dat2);
//打印所有学生的数据
void print_allstu();
//打印学生信息的函数
void print_student(void *dat);
//添加学生的函数
void addstudent();
//保存学生链表到文件中
int save_student(); 
//删除学生
void delstudent();
//修改学生信息
void changestudent();
//登陆学生信息打印
void print_loginstudent();
//学生修改姓名操作
void changestuname();
//学生修改密码操作
void changestupass();
//排序学号
void sort_student_id();
//通过平均成绩排序学生
void sort_student_average();
//通过语文成绩排序学生
void sort_student_chinese();
//通过数学成绩排序学生
void sort_student_math();
//通过C语言成绩排序学生
void sort_student_c();
//id比较函数
int comp_student_id(void *dat1,void *dat2);
//自定义的average比较函数
int comp_student_average(void *dat1,void *dat2);
//自定义的chinese比较函数
int comp_student_chinese(void *dat1,void *dat2);
//自定义的math比较函数
int comp_student_math(void *dat1,void *dat2);
//自定义的c比较函数
int comp_student_c(void *dat1,void *dat2);
//销毁学生链表
void destroy_student(void);
#endif
