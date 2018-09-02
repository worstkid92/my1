#include "MYSQL.h"

struct node *Amend(struct node *head,char c_name[30][30],char amend_name[30],char number[10],char new_data[30],int n)
{
	int m,k = 1,len;
	int number_1 = 0,number_count = 1;
	struct node *l;

	l = head;

	len = strlen(number);

	for(m = len-1;m>=0;m--)
	{
		number_1 = number_1 + (number[m]-48)*k;
		k = k*10;
	}

	for(m = 1;m<=n;m++)
	{
		if(strcmp(c_name[m],amend_name) == 0)
		{
			break;
		}
	}
	
	if(m == n+1)
	{
		return NULL;
	}

	for(;;)
	{
		if(number_count == number_1)
		{
			break;
		}
		else
		{
			if(NULL == l->next)
			{
				return NULL;
			}
			l = l->next;
			number_count++;
		}
	}

	strcpy(l->ch[m],new_data);
	return l;
}