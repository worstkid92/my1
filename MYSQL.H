#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

struct node{
	char ch[30][50];
	struct node *next;
};

struct node *Create(void);																										//��������
void Insert_StructMember(char c_name[30][30],char c_elemtype[30][6],int *n,char s_struct[300]);									//�����ṹ��
void Examine(char c_name[30][30],char c_elemtype[30][6],int *n);																//����������͵������Ƿ�Ϻ�Ҫ��
void Insert_member(struct node *head,char c_name[30][30],char c_elemtype[30][6],int n,char data[100],int insert_temp);			//����Ԫ��
void Print(struct node *head,char c_name[30][30],int n);																		//��ӡ��ǰ����
struct node *Search(struct node *head,char c_name[30][30],char c_elemtype[30][6],char find_name[30],char find_elem[30],int n);	//����Ա����
struct node *Delete(struct node *head,struct node *search_p);																	//����Աɾ��
void fprint(struct node *head,char c_name[30][30],char c_elemtype[30][6],int n,FILE *fp);										//д���ļ���������
struct node *fre(struct node *head,char c_name[30][30],char c_elemtype[30][6],int *n,FILE *fp_1);								//�������
void Insert_member_1(struct node *head,char c_name[30][30],char c_elemtype[30][6],int *n,char insert_member[100]);				//�ٴβ���ṹ���Ա
void Sort(struct node *head,int m,int n,char sort_temp[30],char c_elemtype[30][6]);												//����Ա����
struct node *Search_condition(struct node *head,char c_name[30][30],char c_elemtype[30][6],int n,char search_name[30],char condition[30],char sort_temp[10]);
struct node *Amend(struct node *head,char c_name[30][30],char amend_name[30],char number[10],char new_data[30],int n);
float Operation_column(struct node *head,int m,char operation[10]);
void Incise(char s1[300],char s2[300],int *index,int incise_temp);																//�и��ַ���
void Combine(struct node *head,struct node *head_1,int n);
void Delete_member(struct node *head,char c_name[30][30],char c_elemtype[30][6],int m,int n);
int Compare(char c);
double Calculate(char *cpPoint);