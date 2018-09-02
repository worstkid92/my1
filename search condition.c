#include "MYSQL.h"

struct node *Search_condition(struct node *head,char c_name[30][30],char c_elemtype[30][6],int n,char search_name[30],char condition[30],char sort_temp[10])
{
	int m;
	int temp = 0;
	int int_temp1,int_temp2;
	struct node *l,*last;

	if(strcmp(sort_temp,">") == 0)
	{
		strcpy(sort_temp,"0");
	}
	else
	{
		strcpy(sort_temp,"1");
	}

	l = head;

	last = head;
	for(;;)																			//设定last为最后一个结点首地址
	{
		if(NULL == last->next)
		{
			break;
		}
		else
		{
			last = last->next;
		}
	}

	for(m = 1;m<=n;m++)
	{
		if(strcmp(search_name,c_name[m]) == 0)
		{
			temp = 1;
			break;
		}
	}
	if(temp == 0)
	{
		printf(">>error！\n>>Without the member name!\n\n");
		return NULL;
	}

	if((strcmp(c_elemtype[m],"int") == 0)||(strcmp(c_elemtype[m],"float") == 0))	//确定是什么数据类型
	{
		temp = 1;
	}
	else
	{
		temp = 2;
	}

	Sort(head,m,n,sort_temp,c_elemtype);											//排序

	if(temp == 1)																	//判断首尾元素int float
	{
		if(sort_temp[0] == '1'&&(atof(last->ch[m])>atof(condition)))
			return NULL;
		if(sort_temp[0] == '1'&&(atof(head->ch[m])<atof(condition)))
			return head;
		if(sort_temp[0] == '0'&&(atof(last->ch[m])<atof(condition)))
			return NULL;
		if(sort_temp[0] == '0'&&(atof(head->ch[m])>atof(condition)))
			return head;
	}

	if(temp == 2)																	//判断首尾元素char
	{
		if(sort_temp[0] == '1'&&(strcmp(last->ch[m],condition)>0))
			return NULL;
		if(sort_temp[0] == '1'&&(strcmp(head->ch[m],condition)<0))
			return head;
		if(sort_temp[0] == '0'&&(strcmp(last->ch[m],condition)<0))
			return NULL;
		if(sort_temp[0] == '0'&&(strcmp(head->ch[m],condition)>0))
			return head;
	}
	


	for(l = head;;l = l->next)
	{
		if(temp == 1)																//按int float
		{
			if(atof(l->ch[m])>atof(condition))
				int_temp1=1;
			else if(atof(l->ch[m])<atof(condition))
				int_temp1 = -1;
			else
				int_temp1 = 0;

			if(atof(l->next->ch[m])>atof(condition))
				int_temp2 = 1;
			else if(atof(l->next->ch[m])<atof(condition))
				int_temp2 = -1;
			else
				int_temp2 = 0;


			if(int_temp1*int_temp2<=0)
			{
				return l->next;
			}
		}

		else if(temp == 2)															//按char
		{
			if(strcmp(l->ch[m],condition)*strcmp(l->next->ch[m],condition)<=0)
			{
				return l->next;
			}
		}

		if(l->next == NULL)
		{
			printf("<<error！\n\n");
			return NULL;
		}

	}
}