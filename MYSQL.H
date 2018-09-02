#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

struct node{
	char ch[30][50];
	struct node *next;
};

struct node *Create(void);																										//创建链表
void Insert_StructMember(char c_name[30][30],char c_elemtype[30][6],int *n,char s_struct[300]);									//创建结构体
void Examine(char c_name[30][30],char c_elemtype[30][6],int *n);																//检查数据类型的输入是否合乎要求
void Insert_member(struct node *head,char c_name[30][30],char c_elemtype[30][6],int n,char data[100],int insert_temp);			//插入元素
void Print(struct node *head,char c_name[30][30],int n);																		//打印当前表格
struct node *Search(struct node *head,char c_name[30][30],char c_elemtype[30][6],char find_name[30],char find_elem[30],int n);	//按成员搜索
struct node *Delete(struct node *head,struct node *search_p);																	//按成员删除
void fprint(struct node *head,char c_name[30][30],char c_elemtype[30][6],int n,FILE *fp);										//写入文件，即保存
struct node *fre(struct node *head,char c_name[30][30],char c_elemtype[30][6],int *n,FILE *fp_1);								//读入表格
void Insert_member_1(struct node *head,char c_name[30][30],char c_elemtype[30][6],int *n,char insert_member[100]);				//再次插入结构体成员
void Sort(struct node *head,int m,int n,char sort_temp[30],char c_elemtype[30][6]);												//按成员排序
struct node *Search_condition(struct node *head,char c_name[30][30],char c_elemtype[30][6],int n,char search_name[30],char condition[30],char sort_temp[10]);
struct node *Amend(struct node *head,char c_name[30][30],char amend_name[30],char number[10],char new_data[30],int n);
float Operation_column(struct node *head,int m,char operation[10]);
void Incise(char s1[300],char s2[300],int *index,int incise_temp);																//切割字符串
void Combine(struct node *head,struct node *head_1,int n);
void Delete_member(struct node *head,char c_name[30][30],char c_elemtype[30][6],int m,int n);
int Compare(char c);
double Calculate(char *cpPoint);
