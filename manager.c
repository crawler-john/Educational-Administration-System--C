/*
	 关于管理员具体操作的
			函数
		作者：董笙烽
	  时间：2015/04/11
*/
#include "manager.h"
#include "menu.h"
struct list *list_manager = NULL;
struct list *manlogin;			//需要一个指针用来指向登陆的管理员

//管理员初始化
int init_manager()
{
	FILE *fp;
	struct manager man = {"admin" , "admin"};
	//创建一个链表用于存放管理员的数据
	list_manager = list_create(sizeof(struct manager));
	if(list_manager == NULL)
	{
		return -1;
	}
	//读取manager.dat文件，然后保存所有的数据到链表里面
	fp = fopen("dat/manager.dat","r");
	if(fp == NULL)		//文件不存在
	{
		fp = fopen("dat/manager.dat", "w+");		//创建该文件
		if(fp == NULL)
		{
			list_destroy(&list_manager);
			return -1;
		}
		fwrite(&man, sizeof(man), 1, fp);
		rewind(fp);
	}
	while(1)
	{
		if(fread(&man, sizeof(man), 1, fp) != 1)
		{	//读取文件结束
			if(feof(fp) || ferror(fp))
				break;
		}
		//把man的信息写道链表里面
		if(list_addtail(list_manager, &man) == -1)
		{
			list_destroy(&list_manager);
			fclose(fp);	
			return -1;
		}
	}
	fclose(fp);
	return 0;
}

//管理员的登陆   
int manager_login()
{
	int trycount = 0;
	struct list *find = NULL;
	struct manager man;
	while(trycount < 3)
	{
		show_idmenu();
		scanf("%s",man.name);

		//现从链表中找到  name与输入name相同的管理员
		find = list_find(list_manager,&man, comp_name_man);
		if(find == NULL)
		{
			show_erridmenu();
		}
		else
		{
			show_passmenu();
			scanf("%s",man.pass);
			manlogin = find;//将与输入姓名相同的管理员的位子保存到manlogin中去

		//将该结点的pass和输入的pass做比较
			if(comp_pass_man(((struct manager *)manlogin->dat),&man) == 0)
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
int comp_name_man(void *dat1, void *dat2)
{
	struct manager *man1 = dat1;
	struct manager *man2 = dat2;
	return strcmp(man1->name,man2->name);
}
//用于密码比较
int comp_pass_man(void *dat1, void *dat2)
{
	struct manager *man1 = dat1;
	struct manager *man2 = dat2;
	return strcmp(man1->pass,man2->pass);
	
}
void destroy_manager(void)
{
	list_destroy(&list_manager);
}
