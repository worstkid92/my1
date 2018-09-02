#include "MYSQL.h"

void Insert_StructMember(char c_name[30][30],char c_elemtype[30][6],int *n,char s_struct[300])
{
	int j,s_temp = 1,s_index = 0;

	for(;;)
	{
		(*n)++;
		
		for(j = 0;;j++)
		{
			if(s_temp == 1)
			{
				c_name[*n][j] = s_struct[s_index];
			}
			else
			{
				c_elemtype[*n][j] = s_struct[s_index];
			}
			
			if(s_struct[s_index+1] == ' ')
			{
				if(s_temp == 1)
				{
					c_name[*n][j+1] = '\0';
				}
				else
				{
					c_elemtype[*n][j+1] = '\0';
				}
				
				for(;;)
				{
					s_index++;
					if(s_struct[s_index]!=' ')
					{
						break;
					}
				}
				
				if(s_temp == -1)
				{
					s_temp = -s_temp;
					break;
				}
				
				s_temp=-s_temp;
				
				j=-1;
			}
			else
			{
				s_index++;
				
				if(s_struct[s_index] == '\0')
				{
					c_elemtype[*n][j+1]='\0';
					break;
				}
			}
		}
		
		if(s_struct[s_index] == '\0')
		{
			break;
		}
	}
}