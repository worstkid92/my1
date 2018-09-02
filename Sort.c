#include "MYSQL.h"

void Sort(struct node *head,int m,int n,char sort_temp[30],char c_elemtype[30][6])
{
	int temp,v;
	char s[50];
	struct node *l,*l_1;

	l = head;

	if((strcmp(c_elemtype[m],"int") == 0)||(strcmp(c_elemtype[m],"float") == 0))			//确定数据类型
	{
		temp = 1;
	}
	else if(strcmp(c_elemtype[m],"char") == 0)
	{
		temp = 2;
	}

	for(l = head;l->next!=NULL;l = l->next)													//排序
	{
		for(l_1 = l->next;;l_1 = l_1->next)
		{
			if(temp == 1)																	//按float排序
			{
				if((atof(l->ch[m])-(atof(l_1->ch[m]))>0&&strcmp(sort_temp,"0") == 0)||(atof(l->ch[m])-(atof(l_1->ch[m]))<0&&strcmp(sort_temp,"1") == 0))
				for(v = 1;v<=n;v++)
				{
					strcpy(s,l->ch[v]);
					strcpy(l->ch[v],l_1->ch[v]);
					strcpy(l_1->ch[v],s);
				}
			}
			else																			//按char排序
			{
				if((strcmp(l->ch[m],l_1->ch[m])>0&&strcmp(sort_temp,"0") == 0)||(strcmp(l->ch[m],l_1->ch[m])<0&&strcmp(sort_temp,"1") == 0))
				{
					for(v = 1;v<=n;v++)
					{
						strcpy(s,l->ch[v]);
						strcpy(l->ch[v],l_1->ch[v]);
						strcpy(l_1->ch[v],s);
					}
				}
			}


			if(NULL == l_1->next)
			{
				break;
			}
		}
	}
}