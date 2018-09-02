#include "MYSQL.h"

void main(void)
{
	char order[100],order_1[50];
	char table_name[30];
	char data[100];
	char c_name[30][30],c_elemtype[30][6];
	char s_struct[300];
	char delete_name[30],delete_elem[50];
	char search_name[30],search_elem[50];
	char insert_member[100];
	char sort_name[30];
	char c,sort_temp[30];
	char condition[30],condition_temp[10];
	char operation[10],column_name[30];
	char amend_name[30],number[10],new_data[30];
	char name[100]={"C:\\Users\\1\\Desktop\\c项目\\MYSQL\\"};
	char calculate_s[200],calculate[200];
	char calculate_name[30];
	char order_order[20][40]={"create table","table insert","delete","search","print my table","save my table","read","sort","help","over","search condition","insert member","amend","operation_column","operration_row","combine table","delete member","calculate"};
	                           // 0                1           2        3           4                5           6      7      8       9          10              11             12        13					14				15				16				17
	int index,j,k,name_num;
	int n=0,m,n_count = 0,member_count = 0;
	int insert_temp = 0,temp = 0,order_temp = -1;

	double result;
	char result_s[100];

	char table_1_c_name[30][30],table_1_c_elemtype[30][6];
	int table_1_n;
	int combine_temp = 0;

	float answer;

	FILE *fp,*fp_1;
	FILE *table_1_fp,*table_1_fp_1;

	struct node *head,*search_p,*l;
	struct node *table_1_head;

	printf(">>my sql!\n\n");

	for(;;)																		//开始
	{
		gets(order);

		if(strcmp(order,"start mysql") == 0)
		{
			break;
		}
		else
		{
			printf(">>error!\nplease enter <start mysql>\n\n");
		}
	}

	printf(">>how to use mysql?please enter <help:>\n\n");

	for(;;)																		//检查输入命令
	{
		printf(">>mysql order>>");
		
		gets(order);

		printf("\n");

		for(index = 0;;index++)
		{
			if(order[index]!=':')
			{
				order_1[index] = order[index];
			}
			else
			{
				order_1[index] = '\0';
				break;
			}
		}

		for(m =0;m<=17;m++)
		{
			if(strcmp(order_1,order_order[m]) == 0)
			{
				order_temp = m;
				break;
			}
		}

		if(m == 18)																//命令出错
		{
			printf(">>error!\nWrong order!\n\n");
			continue;
		}

		if(order_temp == 0)														//创建链表
		{
			j = 0;

			for(;;)
			{
				index++;
				if(order[index] == '\0')
				{
					temp = 1;
					printf(">>error!\n>>example:create:my table:name char num int score float\n");
					break;
				}
				if(order[index] == ':')
				{
					table_name[j] = '\0';
					break;
				}
				else
				{
					table_name[j] = order[index];
					j++;
				}
			}
			if(temp == 1)
			{
				temp = 0;
				continue;
			}

			Incise(order,s_struct,&index,0);

			if(n == 0)
			{
				head = Create();
			}

			printf("s_struct = %s",s_struct);

			Insert_StructMember(c_name,c_elemtype,&n,s_struct);
			printf("\n");

			Examine(c_name,c_elemtype,&n);
			printf("\n");

			printf("table_name = %s\n",table_name);
		}

		if(order_temp == 11)													//再次插入结构体成员
		{
			Incise(order,insert_member,&index,0);

			for(j = 0;;j++)
			{
				if(insert_member[j] == '\0')
				{
					n_count++;
					break;
				}
				if(insert_member[j] == ' ')
				{
					n_count++;
				}
			}

			for(l = head;;)
			{
				member_count++;
				if(NULL == l->next)
				{
					break;
				}
				else
				{
					l = l->next;
				}
			}

			if((n_count%(member_count+2))!=0)
			{
				printf(">>error!\n>>example:insert member:name char zcj zwm yxx\n");
				n_count = 0;
				member_count = 0;
				continue;
			}

			n_count = 0;
			member_count = 0;

			Insert_member_1(head,c_name,c_elemtype,&n,insert_member);
		}

		if(order_temp == 1)														//插入表中元素
		{
			j = 0;

			Incise(order,data,&index,0);

			insert_temp++;

			j = 0;
			for(;;)
			{
				if(data[j] == '\0')
				{
					n_count++;
					break;
				}
				if(data[j] == ' ')
				{
					n_count++;
					j++;
				}
				else
				{
					j++;
				}
			}
			printf("n_count = %d\n",n_count);

			if(n_count%n!=0)
			{
				printf(">>error!\n>>n = %d\n",n);
				n_count = 0;
				continue;
			}

			Insert_member(head,c_name,c_elemtype,n,data,insert_temp);

			n_count = 0;
		}

		if(order_temp == 4)														//打印
		{
			printf("\n");
			Print(head,c_name,n);
			printf("\n");
		}

		if(order_temp == 3)														//查找
		{
			Incise(order,search_name,&index,1);

			Incise(order,search_elem,&index,0);

			printf("search_name = %s,search_elem = %s\n",search_name,search_elem);

			search_p = head;

			printf("\n\n>>Search results for:\n");
			for(;;)
			{
				search_p = Search(search_p,c_name,c_elemtype,search_name,search_elem,n);

				if(NULL == search_p)
				{
					printf(">>NULL!\n\n");
					break;
				}

				for(m = 1;m<=n;m++)
				{
					printf("%s:%5s  ",c_name[m],search_p->ch[m]);
				}
				printf("\n");

				if(NULL == search_p->next)
				{
					break;
				}
				else
				{
					search_p = search_p->next;
				}
			}
		}

		if(order_temp == 2)														//删除
		{
			Incise(order,delete_name,&index,1);

			Incise(order,delete_elem,&index,0);

			search_p = Search(head,c_name,c_elemtype,delete_name,delete_elem,n);

			head = Delete(head,search_p);
		}

		if(order_temp == 16)
		{
			Incise(order,delete_name,&index,0);

			for(m = 1;m<=n;m++)
			{
				if(strcmp(c_name[m],delete_name) == 0)
				{
					break;
				}
			}
			if(m == n+1)
			{
				printf(">>error!\n>>Without the member!\n");
				continue;
			}

			Delete_member(head,c_name,c_elemtype,m,n);

			n--;
		}

		if(order_temp == 7)														//排序
		{
			Incise(order,sort_name,&index,1);

			Incise(order,sort_temp,&index,0);

			if(strcmp(sort_temp,"1")!=0&&strcmp(sort_temp,"0")!=0)
			{
				printf(">>error!\n>>Please choose the ascending order<0> or descending order<1>\n");
				continue;
			}

			for(m = 1;m<=n;m++)
			{
				if(strcmp(sort_name,c_name[m]) == 0)
				{
					break;
				}
			}
			if(m == n+1)
			{
				printf(">>error!\n>>Without this structure members!\n");
				continue;
			}

			printf("sort_name = %s,sort_temp = %s\n",sort_name,sort_temp);

			Sort(head,m,n,sort_temp,c_elemtype);
		}

		if(order_temp == 10)
		{
			Incise(order,search_name,&index,1);

			Incise(order,condition_temp,&index,1);

			Incise(order,condition,&index,0);

			for(m = 1;m<=n;m++)
			{
				if(strcmp(c_name[m],search_name) == 0)
				{
					break;
				}
			}

			printf("search_name = %s,condition_temp = %s,condition = %s\n",search_name,condition_temp,condition);

			if((strcmp(condition_temp,">")!=0&&strcmp(condition_temp,"<")!=0)||m == n+1)
			{
				printf(">>error!\n>>example:search condition:score > 80\n\n");
			}

			search_p = Search_condition(head,c_name,c_elemtype,n,search_name,condition,condition_temp);

			printf("\n\n>>Search results for:\n");
			Print(search_p,c_name,n);
		}

		if(order_temp == 12)													//修改元素内的值
		{
			Incise(order,amend_name,&index,1);

			Incise(order,number,&index,1);

			Incise(order,new_data,&index,0);

			search_p = Amend(head,c_name,amend_name,number,new_data,n);

			if(NULL == search_p)
			{
				printf(">>error!\n>>example:amend:score 4 90\n\n");
				continue;
			}
		}

		if(order_temp == 13)													//列运算
		{
			Incise(order,operation,&index,1);

			if(strcmp(operation,"sum")!=0&&strcmp(operation,"average")!=0)
			{
				printf(">>error!\n>>please enter sum or average\n\n");
				continue;
			}

			Incise(order,column_name,&index,0);

			for(m = 1;m<=n;m++)
			{
				if(strcmp(c_name[m],column_name) == 0)
				{
					break;
				}
			}
			if(m == n+1)
			{
				printf(">>error!\n>>Without the member_name\n\n");
				continue;
			}

			if(strcmp(c_elemtype[m],"char") == 0)
			{
				printf(">>error!\n>>the elemtype of member is char!\n\n");
				continue;
			}

			answer = Operation_column(head,m,operation);

			printf("\n>>answer = %f\n\n",answer);
		}

		if(order_temp == 17)													//列间运算
		{
			l = head;

			Incise(order,calculate_s,&index,0);

			printf("calculate_s = %s\n",calculate_s);

			strcpy(c_name[n+1],"result");
			strcpy(c_elemtype[n+1],"double");

			for(;;)
			{
				j = 0;
				for(k = 0;;)
				{
					if(calculate_s[k] == '\0')
					{
						calculate[j] = '=';
						calculate[j+1] = '\0';
						break;
					}

					if(Compare(calculate_s[k]) == 1)
					{
						calculate[j] = calculate_s[k];
						j++;
						k++;
					}
					else
					{
						for(name_num = 0;;name_num++)
						{
							if(Compare(calculate_s[k]) == 1||calculate_s[k] == '\0')
							{
								calculate_name[name_num] = '\0';
								break;
							}

							calculate_name[name_num] = calculate_s[k];
							k++;
						}

						for(m = 1;m<=n;m++)
						{
							if(strcmp(c_name[m],calculate_name) == 0)
							{
								break;
							}
						}

						strcpy(&calculate[j],l->ch[m]);
						j = j+strlen(l->ch[m]);
					}
				}

				//printf("calculate = %s\n",calculate);

				result = Calculate(calculate);

				sprintf(result_s,"%.3lf",result);

				strcpy(l->ch[n+1],result_s);

				if(NULL == l->next)
				{
					break;
				}
				else
				{
					l = l->next;
				}
			}

			n++;
		}

		if(order_temp == 15)													//合并表格
		{
			Incise(order,table_name,&index,2);

			fp = fopen(table_name,"r");

			if(NULL == fp)
			{
				printf(">>error!\n\n");
				continue;
			}

			fp_1 = fp;

			printf("table_name = %s\n\n",table_name);

			head = fre(head,c_name,c_elemtype,&n,fp_1);

			for(m = 1;m<=n;m++)
			{
				printf("c_name[%d] = %s    ",m,c_name[m]);
			}
			printf("\n\n");

			for(m = 1;m<=n;m++)
			{
				printf("c_elemtype[%d] = %s    ",m,c_elemtype[m]);
			}
			printf("\n\n");

			fclose(fp);

			insert_temp++;

			Incise(order,table_name,&index,0);

			table_1_fp = fopen(table_name,"r");

			if(NULL == table_1_fp)
			{
				printf(">>error!\n\n");
				continue;
			}

			table_1_fp_1 = table_1_fp;

			printf("table_name_1 = %s\n\n",table_name);

			table_1_head = fre(table_1_head,table_1_c_name,table_1_c_elemtype,&table_1_n,table_1_fp_1);

			for(m = 1;m<=table_1_n;m++)
			{
				printf("c_name[%d] = %s    ",m,table_1_c_name[m]);
			}
			printf("\n\n");

			for(m = 1;m<=table_1_n;m++)
			{
				printf("c_elemtype[%d] = %s    ",m,table_1_c_elemtype[m]);
			}
			printf("\n\n");

			fclose(table_1_fp);

			insert_temp++;

			if(n!=table_1_n)
			{
				printf(">>error!\n");
				continue;
			}

			for(m = 1;m<=n;m++)
			{
				if(strcmp(c_name[m],table_1_c_name[m])!=0||strcmp(c_elemtype[m],table_1_c_elemtype[m])!=0)
				{
					combine_temp = 1;
					break;
				}
			}

			if(combine_temp == 1)
			{
				combine_temp = 0;
				printf(">>error!\n");
				continue;
			}

			Combine(head,table_1_head,n);
		}

		if(order_temp == 5)														//保存当前表格
		{
			Incise(order,table_name,&index,0);

			fp = fopen(table_name,"w+");

			fp_1 = fp;

			fprint(head,c_name,c_elemtype,n,fp_1);

			fclose(fp);
		}

		if(order_temp == 6)														//读取表格
		{
			if(order[index+1] == '\0')
			{
				printf(">>error!\n>>No table name!\n>>example:read:my table\n\n");
				continue;
			}

			Incise(order,table_name,&index,0);

			fp = fopen(table_name,"r");

			if(NULL == fp)
			{
				printf(">>error!\n\n");
				continue;
			}

			fp_1 = fp;

			printf("table_name = %s\n\n",table_name);

			head = fre(head,c_name,c_elemtype,&n,fp_1);

			for(m = 1;m<=n;m++)
			{
				printf("c_name[%d] = %s    ",m,c_name[m]);
			}
			printf("\n\n");

			for(m = 1;m<=n;m++)
			{
				printf("c_elemtype[%d] = %s    ",m,c_elemtype[m]);
			}
			printf("\n\n");

			fclose(fp);

			insert_temp++;
		}

		if(order_temp == 8)														//显示帮助信息
		{
			fp = fopen("help.txt","r");

			fp_1 = fp;

			printf("\n\n>>help:\n\n");

			while((c = fgetc(fp_1))!=EOF)
			{
				putchar(c);
			}

			fclose(fp);
		}

		if(order_temp == 9)														//结束访问
		{
			printf("byebye!\n");
			break;
		}
	}
}