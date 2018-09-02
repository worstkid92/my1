#include "MYSQL.h"

#define MAXEXPLEN  150

short ucPriprity_Justify(unsigned char);
double fCalculate_Operation(double,char,double);

short iErr_Flag=0;

short ucPriprity_Justify(unsigned char Operator)
{
	switch(Operator)
		{
	     case '+':return(1);
		 case '-':return(1);
		 case '*':return(2);
		 case '/':return(2);
		 case '(':return(0);	
		 default:return(0xff);
		}
}

double fCalculate_Operation(double fNum1,char cSymbol,double fNum2)
{
	switch(cSymbol)
	{
	    case '+':return(fNum1+fNum2);
		case '-':return(fNum1-fNum2);
		case '*':return(fNum1*fNum2);
		case '/':
		 if(fNum2<0.0001 && fNum2> -0.0001)
			{iErr_Flag=1;
		      return(0);
			}
		 else return(fNum1/fNum2);
	}
}

double Calculate(char *cpPoint)
{
	double Num_Stack[MAXEXPLEN];
	double fFormer_Num,fLater_Num;
	unsigned char Operator_Stack[MAXEXPLEN];
	short i=0,j=0;

	char Num[100];
	int k=0;

	iErr_Flag=0;

	while(*cpPoint!='\0')
	{
	    if((i>MAXEXPLEN)||(j>MAXEXPLEN)||(iErr_Flag==1))
	    	{
	    	 iErr_Flag=0;
	    	 return(0);	    	 
	    	}
		if((*cpPoint>='0')&&(*cpPoint<='9')||*cpPoint == '.')
			{
			 Num[k]=*cpPoint;
			 k++;
			 cpPoint++;
			 while((*cpPoint>='0')&&(*cpPoint<='9')||*cpPoint == '.')
			 {
				 Num[k]=*cpPoint;
				 k++;
				 cpPoint++;
			 }

			 Num[k]='\0';
			 Num_Stack[i]=atof(Num);
			 i++;	
			 k=0;
			}
		else			
		switch(*cpPoint)
		{
			case '+':
			case '-':
			case '*':
			case '/':
				if(j==0)
					{
					 Operator_Stack[j]=*cpPoint;
					 j++;
					 cpPoint++;
					}
				else if(ucPriprity_Justify(*cpPoint)>ucPriprity_Justify(Operator_Stack[j-1]))Operator_Stack[j++]=*cpPoint++;
				else 
					{
					 fLater_Num=Num_Stack[--i];
					 fFormer_Num=Num_Stack[--i];
					 Num_Stack[i++]=fCalculate_Operation(fFormer_Num,Operator_Stack[--j],fLater_Num);
					}
				break;	
			case '(':Operator_Stack[j++]=*cpPoint++;break;
			case ')':
				if(Operator_Stack[j-1]=='('){j--,cpPoint++;}
				else 
				    {
					 fLater_Num=Num_Stack[--i];
					 fFormer_Num=Num_Stack[--i];
					 Num_Stack[i++]=fCalculate_Operation(fFormer_Num,Operator_Stack[--j],fLater_Num);
					}
				break;
			case '=':
				if(j!=0)
					{
					 fLater_Num=Num_Stack[--i];
					 fFormer_Num=Num_Stack[--i];
					 Num_Stack[i++]=fCalculate_Operation(fFormer_Num,Operator_Stack[--j],fLater_Num);
					}
				else return(Num_Stack[0]);
				break;
			default:
				iErr_Flag=1;
	    	    return(0);
				break;
		}
	}
}