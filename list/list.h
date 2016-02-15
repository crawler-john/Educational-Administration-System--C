/*
		文件名：list.h
	可以存放任意数据的双链表的基本操作
		以及文件的读写操作
		2015/4/7	董笙烽


*/

#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list
{
	void *dat;
	int  size;
	struct list *next;
	struct list *prev;
};

typedef void (*print_f)(void *);
typedef int (*compare_f)(void *, void *);
typedef void (*fprint_f)(void *);

//创建一个链表头
struct list *list_create(int size);

//把一个数据插入到链表头的后面
int list_addhead(struct list *head, void *dat);

//把一个数据插入到链表尾的后面
int list_addtail(struct list *head, void *dat);

//链表的查找函数,在链表中查找一个数据
struct list *list_find(struct list *head, void *dat, compare_f compare);

//在链表中查找所有的与dat相同的数据
struct list *list_findall(struct list *head, void *dat, compare_f compare);

//从链表中删除一个数据
void list_del(struct list *head, void *dat, compare_f compare);

//从链表中删除所有的等于dat的数据
void list_delall(struct list *head, void *dat, compare_f compare);

//打印链表
void list_print(struct list *head, print_f  print);

//销毁链表
void list_destroy(struct list **entry);
//链表的排序
void list_sort(struct list *head, compare_f compare);
#endif /* __LIST_H__*/
