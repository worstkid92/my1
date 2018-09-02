#include "MYSQL.h"

int Compare(char c)
{
	if((c>='0'&&c<='9')||c == '.')
	{
		return 1;
	}
	else
	{
		switch(c){
		case '+':
		case '-':
		case '*':
		case '/':
		case '(':
		case ')':
			return 1;
		default:
			return 0;
		}
	}
}