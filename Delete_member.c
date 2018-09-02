#include "MYSQL.h"

void Delete_member(struct node *head,char c_name[30][30],char c_elemtype[30][6],int m,int n)
{
	int i;
	struct node *l;

	l = head;

	for(i = m;i<n;i++)
	{
		strcpy(c_name[i],c_name[i+1]);
		strcpy(c_elemtype[i],c_elemtype[i+1]);
	}

	for(;;)
	{
		for(i = m;i<n;i++)
		{
			strcpy(l->ch[i],l->ch[i+1]);
		}
		if(NULL == l->next)
		{
			break;
		}
		else
		{
			l = l->next;
		}
	}
}