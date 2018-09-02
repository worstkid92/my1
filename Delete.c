#include "MYSQL.h"

struct node *Delete(struct node *head,struct node *search_p)
{
	struct node *l;
	
	l = head;
	
	if(l == search_p)				//如果是第一个元素，则进行特殊处理
	{
		return head->next;
	}
	
	for(;l->next!=search_p;)
	{
		l = l->next;
	}
	
	l->next = search_p->next;
	
	return head;
}