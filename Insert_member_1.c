#include "MYSQL.h"

void Insert_member_1(struct node *head,char c_name[30][30],char c_elemtype[30][6],int *n,char insert_member[100])
{
	int j,index = 0;
	struct node *l;

	l = head;

	for(;;)
	{
		(*n)++;

		j = 0;
		for(;;)
		{
			if(insert_member[index]!=' ')
			{
				c_name[*n][j] = insert_member[index];
				j++;
				index++;
			}
			else
			{
				c_name[*n][j] = '\0';
				j = 0;
				break;
			}
		}

		index++;
		for(;;)
		{
			if(insert_member[index]!=' ')
			{
				c_elemtype[*n][j] = insert_member[index];
				j++;
				index++;
			}
			else
			{
				c_elemtype[*n][j] = '\0';
				j = 0;
				break;
			}
		}

		if(strcmp(c_elemtype[*n],"int")!=0&&strcmp(c_elemtype[*n],"float")!=0&&strcmp(c_elemtype[*n],"char")!=0)
		{
			printf("\n  ??The variable <%s> data types can't for <%s>\n>>please enter:",c_name[*n],c_elemtype[*n]);
			gets(c_elemtype[*n]);
		}

		index++;
		j = 0;
		for(;;)
		{
			for(;;)
			{
				if(insert_member[index] == ' '||insert_member[index] == '\0')
				{
					l->ch[*n][j] = '\0';
					j = 0;
					break;
				}
				else
				{
					l->ch[*n][j] = insert_member[index];
					j++;
					index++;
				}
			}
			if(NULL == l->next)
			{
				break;
			}
			else
			{
				l = l->next;
				index++;
			}
		}
		if(insert_member[index] == '\0')
		{
			break;
		}
		else
		{
			l = head;
			index++;
		}
	}
}