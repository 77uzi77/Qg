#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MaxSize 50
//定义两个顺序栈，分别用于两个功能

 
//用于 中缀转换成后缀时，将各个运算符压入栈中 
typedef struct
{
	char data[MaxSize];
	int top;
} SeqStack;
//用于 计算后缀表达式的值时，将各个运算数压入栈中 
typedef struct
{
	float data[MaxSize];
	int top;
} OpStack;


void InitStack(SeqStack *S) ; //初始化栈
int StackEmpty(SeqStack S) ; //判断栈是否为空
int PushStack(SeqStack *S, char e) ; //进栈
int PopStack(SeqStack *S, char *e) ; //弹栈 
int GetTop(SeqStack S, char *e) ; //得到栈顶元素
void TranslateExpress(char s1[], char s2[]) ; //将中缀表达式转化为后缀表达式
float ComputeExpress(char s[]) ; //计算后缀表达式的值

#endif 

