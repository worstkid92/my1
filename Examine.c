#include "MYSQL.h"

void Examine(char c_name[30][30],char c_elemtype[30][6],int *n)
{
	int m,num = 10;
	char c_m[100][20] = {"qq","1th","2th","3th","4th","5th","6th","7th","8th","9th"}; 

	for(m = 10;m<100;m++)
	{
		c_m[m][0] = num/10 + 48;
		c_m[m][1] = num%10 + 48;
		c_m[m][2] = 't';
		c_m[m][3] = 'h';
		c_m[m][4] = '\0';
		num++;
	}
	
	for(m = 1;m<=*n;m++)		//检查输入是否符合要求
	{
		if(strcmp(c_elemtype[m],"char")!=0&&strcmp(c_elemtype[m],"int")!=0&&strcmp(c_elemtype[m],"float")!=0)
		{
			printf("error！\n  ??The %s members of the data type can't for<%s>,please enter(char,int,float)\n\n",c_m[m],c_elemtype[m],c_elemtype[m]);
			
			for(;;)
			{
				gets(c_elemtype[m]);
				if(strcmp(c_elemtype[m],"char")!=0&&strcmp(c_elemtype[m],"int")!=0&&strcmp(c_elemtype[m],"float")!=0)
				{
					printf("error！\nThe %s members of the data type can't for integer<%s>,please enter(char,int,float)\n\n",c_m[m],c_name[m],c_elemtype[m]);
				}
				else
				{			
					break;
				}
			}
		}
	}
	
	for(m = 1;m<=*n;m++)		//输出成员名和数据类型
	{
		printf("%s:%s    ",c_name[m],c_elemtype[m]);
	}
	printf("\n");
}