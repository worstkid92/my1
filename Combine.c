#include "MYSQL.h"

void Combine(struct node *head,struct node *head_1,int n)
{
	int m;
	int temp = 0;
	struct node *head_l,*head_1_l,*head_l1;

	head_l = head;
	head_l1 = head;

	head_1_l = head_1;

	for(;;)
	{
		if(NULL == head_l->next)
		{
			break;
		}
		else
		{
			head_l = head_l->next;
		}
	}

	for(;;)
	{
		head_l->next = (struct node*)malloc(sizeof(struct node));
		head_l = head_l->next;

		for(;;)
		{
			for(m = 1;m<=n;m++)
			{
				if(strcmp(head_l1->ch[m],head_1_l->ch[m])!=0)
				{
					temp = 1;
					break;
				}
			}

			if(temp == 1)
			{
				temp = 0;
				break;
			}

			if(NULL == head_l1->next)
			{
				break;
			}
			else
			{
				head_l1 = head_l1->next;
			}
		}

		head_l1 = head;

		for(m = 1;m<=n;m++)
		{
			strcpy(head_l->ch[m],head_1_l->ch[m]);
		}

		if(NULL == head_1_l->next)
		{
			head_l->next = NULL;
			break;
		}
		else
		{
			head_1_l = head_1_l->next;
		}
	}
}