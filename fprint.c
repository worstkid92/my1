#include "MYSQL.h"

void fprint(struct node *head,char c_name[30][30],char c_elemtype[30][6],int n,FILE *fp)
{
	int i,m;
	struct node *l;

	l = head;

	fprintf(fp,"n = %d\n",n);		//写入n

	fprintf(fp,"c_name:\n");

	for(i = 1;i<=n;i++)				//写入c_name
	{
		fprintf(fp,"%s  ",c_name[i]);
	}
	fprintf(fp,"\n\n");

	fprintf(fp,"c_elemtype:\n");
	for(i = 1;i<=n;i++)				//写入c_elemtype
	{
		fprintf(fp,"%s  ",c_elemtype[i]);
	}
	fprintf(fp,"\n\n");

	for(;;)							//写入数据
	{
		for(m = 1;m<=n;m++)
		{
			fprintf(fp,"%s  ",l->ch[m]);
		}
		fprintf(fp,";\n");

		if(NULL == l->next)
		{
			break;
		}
		else
		{
			l = l->next;
		}
	}
}