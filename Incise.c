#include "MYSQL.h"

void Incise(char s1[300],char s2[300],int *index,int incise_temp)
{
	int j = 0;

	for(;;)
	{
		(*index)++;
		if((s1[*index] == ' '&&incise_temp == 1)||(s1[*index] == '\0'&&incise_temp == 0)||(s1[*index] == ':'&&incise_temp == 2))
		{
			s2[j] = '\0';
			break;
		}
		else
		{
			s2[j] = s1[*index];
			j++;
		}
	}
}