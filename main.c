/*
			主函数
		作者：董笙烽
	  时间：2015/04/11
*/
#include "menu.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
static int init(void); // 初始化函数
static void destroy_all(void); //销毁全部链表
int main(void)
{
	int ret;
	printf("\033[?25l");
	ret = init();
	if(ret != 0)
	{
		printf("init_error %d\n",ret);
		return -1;
	}

	menu_operation();	
	//结束操作，销毁全部链表
	destroy_all();
}


//初始化函数
static int init(void)
{
	//1管理员信息初始化	
	if(init_manager() != 0)
	{
		return -1;
	}
	//2教师信息初始化
	if(init_student() != 0)
	{
		return -2;
	}
	//3学生信息初始化
	if(init_teacher() != 0)
	{
		return -3;
	}
	return 0;
	
}	
static void destroy_all(void)
{
	//管理员链表销毁
	destroy_manager();
	//教师链表销毁
	destroy_teacher();
	//学生链表销毁
	destroy_student();
	CLEAR_SCREEN();
	printf("\033[34m\033[2;60H%s\033[0m","感谢您的使用谢谢!\n");
	getchar();
	getchar();
	printf("\033[?25h");
}
