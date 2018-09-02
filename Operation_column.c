#include "MYSQL.h"

float Operation_column(struct node *head,int m,char operation[10])
{
	float answer = 0;
	int c = 0;
	struct node *l;

	l = head;

	for(;;)
	{
		answer = answer + atof(l->ch[m]);

		c++;

		if(NULL == l->next)
		{
			break;
		}
		else
		{
			l = l->next;
		}
	}

	if(strcmp(operation,"sum") == 0)
	{
		return answer;
	}
	else
	{
		return answer/c;
	}
}