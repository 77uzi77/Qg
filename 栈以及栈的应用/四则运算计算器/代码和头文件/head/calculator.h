#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MaxSize 50
//��������˳��ջ���ֱ�������������

 
//���� ��׺ת���ɺ�׺ʱ�������������ѹ��ջ�� 
typedef struct
{
	char data[MaxSize];
	int top;
} SeqStack;
//���� �����׺���ʽ��ֵʱ��������������ѹ��ջ�� 
typedef struct
{
	float data[MaxSize];
	int top;
} OpStack;


void InitStack(SeqStack *S) ; //��ʼ��ջ
int StackEmpty(SeqStack S) ; //�ж�ջ�Ƿ�Ϊ��
int PushStack(SeqStack *S, char e) ; //��ջ
int PopStack(SeqStack *S, char *e) ; //��ջ 
int GetTop(SeqStack S, char *e) ; //�õ�ջ��Ԫ��
void TranslateExpress(char s1[], char s2[]) ; //����׺���ʽת��Ϊ��׺���ʽ
float ComputeExpress(char s[]) ; //�����׺���ʽ��ֵ

#endif 

