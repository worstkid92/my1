#include "MYSQL.h"

struct node *Search(struct node *head,char c_name[30][30],char c_elemtype[30][6],char find_name[30],char find_elem[30],int n)
{
	int m;
	int temp = 0;
	struct node *l;
	
	l = head;
	
	for(m = 1;m<=n;m++)
	{
		if(strcmp(find_name,c_name[m]) == 0)						//确定按哪个成员进行操作
		{
			temp = 1;
			break;
		}
	}
	if(temp == 0)
	{
		printf(">>error!\n>>Without the member!\n");
		return NULL;
	}
	
	for(;;)
	{
		if(strcmp(l->ch[m],find_elem) == 0)
		{
			return l;
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
	
	return NULL;
}