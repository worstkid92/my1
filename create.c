#include "MYSQL.h"

struct node *Create(void)
{
	struct node *head;
	
	head = (struct node*)malloc(sizeof(struct node));
	head->next = NULL;
	
	return head;
}