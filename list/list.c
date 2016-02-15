/*
		文件名：list.c
	可以存放任意数据的双链表的基本操作
		以及文件的读写操作
		2015/4/7	董笙烽


*/



#include "list.h"


//创建一个链表头
struct list *list_create(int size)
{
	struct list *head = NULL;

	head = malloc(sizeof(struct list));
	if(head == NULL)
	{
		printf("malloc head error!!!\n");
		return NULL;
	}

	head->dat = NULL;	
	head->size = size;
	head->next = head->prev = head;

	return head;
}

//把new这个结点连接到prev与next之间
static void _insert(struct list *prev, struct list *next, struct list *new)
{
	prev->next = new;
	next->prev = new;
	new->prev = prev;
	new->next = next;
}

//把一个数据插入到链表头的后面
int list_addhead(struct list *head, void *dat)
{
	struct list *new = NULL;

	//为结点分配空间
	new = malloc(sizeof(struct list));
	if(new == NULL)	
	{
		printf("malloc new error!!!\n");
		return -1;
	}

	//为结点存放数据分配空间
	new->size = head->size;
	new->dat = malloc(new->size);
	if(new->dat == NULL)
	{
		printf("malloc new dat error!!!\n");
		free(new);
		return -1;
	}

	//把数据拷贝到new结点里面
	memcpy(new->dat, dat, new->size);
	
	//把结点连接到链表头的后面
	_insert(head, head->next, new);

	return 0;
}


//把一个数据插入到链表尾的后面
int list_addtail(struct list *head, void *dat)
{
	struct list *new = NULL;

	//为结点分配空间
	new = malloc(sizeof(struct list));
	if(new == NULL)	
	{
		printf("malloc new error!!!\n");
		return -1;
	}

	//为结点存放数据分配空间
	new->size = head->size;
	new->dat = malloc(new->size);
	if(new->dat == NULL)
	{
		printf("malloc new dat error!!!\n");
		free(new);
		return -1;
	}

	//把数据拷贝到new结点里面
	memcpy(new->dat, dat, new->size);
	
	//把结点连接到链表尾的后面
	_insert(head->prev, head, new);

	return 0;
}


//链表的查找函数,在链表中查找一个数据
struct list *list_find(struct list *head, void *dat, compare_f compare)
{
	struct list *tmp;

	for(tmp = head->next; tmp != head; tmp = tmp->next)	
	{
		//调作回调函数对数据进行比较
		if(compare(dat, tmp->dat) == 0)
		{
			return tmp;	
		}
	}

	return NULL;
}

//在链表中查找所有的与dat相同的数据
struct list *list_findall(struct list *head, void *dat, compare_f compare)
{
	struct list *tmp, *result = NULL;

	for(tmp = head->next; tmp != head; tmp = tmp->next)		
	{
		//调作回调函数对数据进行比较
		if(compare(dat, tmp->dat) == 0)
		{
			if(result == NULL)
			{
				result = list_create(head->size);
			}
			list_addtail(result, tmp->dat);
		}
	}

	//返回链表，该链表里面存放了查找到的所有数据
	return result;	
}

//从链表中删除一个数据
void list_del(struct list *head, void *dat, compare_f compare)
{
	struct list *tmp;

	for(tmp = head->next; tmp != head; tmp = tmp->next)	
	{
		if(compare(dat, tmp->dat) == 0)
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			free(tmp);
			break;
		}
	}
}

//从链表中删除所有的等于dat的数据
void list_delall(struct list *head, void *dat, compare_f compare)
{
	struct list *tmp, *next;

	for(tmp = head->next; tmp != head; tmp = next)	
	{
		next = tmp->next;
		if(compare(dat, tmp->dat) == 0)
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			free(tmp->dat);
			free(tmp);
		}
	}
}

//打印链表
void list_print(struct list *head, print_f  print)
{
	struct list *tmp;

	for(tmp = head->next; tmp != head; tmp = tmp->next)
	{
		print(tmp->dat);
	}

	printf("\n");
}

//销毁链表
void list_destroy(struct list **entry)
{
	struct list *head, *tmp, *next;

	if((entry == NULL) || (*entry == NULL))
		return;
	
	head = *entry;
	for(tmp = head->next; tmp != head; tmp = next)
	{
		next = tmp->next;
		free(tmp->dat);
		free(tmp);
	}
	free(head);

	*entry = NULL;
}

void list_sort(struct list *head, compare_f compare)
{
	struct list *tmp, *new, *cur;			

	if((head->next == head) || (head->next->next == head))	
	{
		return;
	}

	//创建一个新链表头
	new = list_create(head->size);

	//从head里面取出第一个结点放到new链表里面去
	cur = head->next;	
	head->next = cur->next;
	cur->next->prev = head;
	_insert(new, new->next, cur);

	
	while(head->next != head)
	{
		cur = head->next;	
		head->next = cur->next;
		cur->next->prev = head;

		for(tmp = new->next; tmp != new; tmp = tmp->next)	
		{
			if(compare(cur->dat, tmp->dat) <= 0)
			{
				_insert(tmp->prev, tmp, cur);
				break;
			}
		}

		if(tmp == new)
		{
			_insert(new->prev, new, cur);
		}
	}

	//更换链表头
	head->next = new->next;	
	new->next->prev = head;
	new->prev->next = head;
	head->prev = new->prev;
}
