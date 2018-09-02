#include "MYSQL.h"

void Print(struct node *head,char c_name[30][30],int n)
{
	int m,count = 1,num = 10;
	char c_m[100][20] = {"qq","1th","2th","3th","4th","5th","6th","7th","8th","9th"};
	struct node *l;

	for(m = 10;m<100;m++)
	{
		c_m[m][0] = num/10 + 48;
		c_m[m][1] = num%10 + 48;
		c_m[m][2] = 't';
		c_m[m][3] = 'h';
		c_m[m][4] = '\0';
		num++;
	}
	
	l = head;
	
	printf("                 ");
	for(m = 1;m<=n;m++)
	{
		printf("%7s",c_name[m]);
	}
	printf("\n");
	
	for(;;)
	{
		printf("The%5s member:",c_m[count]);
		for(m = 1;m<=n;m++)
		{
			printf("%7s",l->ch[m]);
		}
		printf("\n");
		if(NULL == l->next)
		{
			break;
		}
		
		l = l->next;	
		count++;
	}
	printf("\n\n");
	
}