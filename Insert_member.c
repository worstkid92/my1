#include "MYSQL.h"

void Insert_member(struct node *head,char c_name[30][30],char c_elemtype[30][6],int n,char data[100],int insert_temp)
{
	int m = 0,j,k,index = 0;
	int ins_temp = 0;
	struct node *l;
	
	l = head;

	for(;;)											//�������λ��������ǰ�Ŀ�λ
	{
		if(insert_temp == 1)						//��һ�β���, �������
		{
			break;
		}
		else if(head->next == NULL)
		{
			l->next = (struct node *)malloc(sizeof(struct node));
			l = l->next;
		}
		else if(l->next == NULL)
		{
			l->next = (struct node *)malloc(sizeof(struct node));
			l = l->next;
			break;
		}
		else
		{
			l = l->next;
		}
	}
	
	for(;;)
	{
		m++;
		
		for(j=0;;j++)
		{
			for(k = 1;k<=n;k++)
			{
				if(ins_temp%(n)+1 == k)
				{
					l->ch[k][j] = data[index];
				}
			}
			
			if(data[index+1] == ' ')
			{
				for(k = 1;k<=n;k++)
				{
					if(ins_temp%n+1 == k)
					{
						l->ch[k][j+1] = '\0';
					}
				}
				
				for(;;)								//���ո�
				{
					index++;
					if(data[index]!=' ')
					{
						break;
					}
				}
				
				ins_temp++;
				
				j = -1;
				
				if(ins_temp%(n) == 0)
				{
					break;
				}
			}
			else
			{
				index++;
				
				if(data[index] == '\0')
				{
					l->ch[n][j+1] = '\0';
					break;
				}
			}
		}
		
		if(data[index] == '\0')						//�������
		{
			break;
		}
		l->next = (struct node *)malloc(sizeof(struct node));
		l = l->next;
	}
	
	l->next = NULL;
}