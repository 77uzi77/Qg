#include "../head/calculator.h"


void InitStack(SeqStack *S) //初始化栈
{
	S->top = 0;
}

int StackEmpty(SeqStack S) //判断栈是否为空
{
	if(S.top == 0) 
	return 1;
	else 
	return 0;
}
int PushStack(SeqStack *S, char e) //进栈
{
	if(S->top >= MaxSize)
	{
		printf("栈已满， 不能进栈!") ;
		return 0;
	}
	else
	{
		S->data[S->top] = e;
		S->top++;
		return 1;
	}
}
int PopStack(SeqStack *S, char *e) //删除栈顶元素
{
	if(S->top == 0){
		printf("栈已空\n") ;
		return 0;
	}
	else{
		S->top--;
		*e = S->data[S->top];
		return 1;
	}
}
int GetTop(SeqStack S, char *e) //取栈顶元素
{
	if(S.top <= 0){
		printf("栈已空") ;
		return 0;
	}
	else{
		*e = S.data[S.top-1];
		return 1;
	}
}

//把中缀表达式转换为后缀表达式
void TranslateExpress(char str[], char exp[]) 
{
	SeqStack S;
	char ch;
	char e;
	int i=0, j=0;
	InitStack(&S);
	ch=str[i];
	i++;
	//依次扫描中缀表达式
	while(ch!='\0' ) {
		switch(ch){
			case'(' :
				PushStack(&S, ch) ;
				break;
			case')' :
				while(GetTop(S, &e) &&e!='(' ){
					PopStack(&S, &e) ;
					exp[j]=e;
					j++;
				}
				PopStack(&S, &e) ;
				break;
			case'+' :
			case'-' :
				while(!StackEmpty(S) &&GetTop(S, &e) &&e!='(' ){
					PopStack(&S, &e) ;
					exp[j]=e;
					j++;
				}
				PushStack(&S, ch) ;
				break;
			case'*' :
			case'/' :
				while(!StackEmpty(S) &&GetTop(S, &e) &&e=='/' || e=='*' ){
					PopStack(&S, &e) ;
					exp[j]=e;
					j++;
				}
				PushStack(&S, ch) ;
				break; 
				//是空格就忽略
			case' ' :
				break;
			default:
				while(ch>='0' &&ch<='9' ){
					exp[j]=ch;
					j++;
					ch=str[i];
					i++;
				}
				i--;
				exp[j]=' ';
				j++;
			}
		ch=str[i];
		i++;
	}
	//将栈中剩余运算符出栈
	while(!StackEmpty(S) ) {
		PopStack(&S, &e) ;
		exp[j]=e;
		j++;
	}
	exp[j]='\0';
}

//计算后缀表达式的值
float ComputeExpress(char a[]) {
	
	OpStack S;
	int i=0;
	float x1, x2, value;
	float result;
	S.top=-1;
	//依次扫描后缀表达式
	while(a[i]!='\0' ) {
		//如果是数字
		if(a[i]!=' ' &&a[i]>='0' &&a[i]<='9' ) {
			value=0;
			//如果不是空格
			while(a[i]!=' ' ) {
				value=10*value+a[i]-'0';
				i++;
			}
			S.top++;
			S.data[S.top]=value; 
		}
		//如果是运算符
		else {
			switch(a[i]){
				case'+' :
					x1=S.data[S.top];
					S.top--;
					x2=S.data[S.top];
					S.top--;
					result=x1+x2;
					S.top++;
					S.data[S.top]=result;
					break;
				case'-' :
					x1=S.data[S.top];
					S. top--;
					x2=S.data[S.top];
					S.top--;
					result=x2-x1;
					S.top++;
					S.data[S.top]=result;
					break;
				case'*' :
					x1=S. data[S.top];
					S.top--;
					x2=S.data[S.top];
					S.top--;
					result=x1*x2;
					S.top++;
					S.data[S.top]=result;
					break;
				case'/' :
					x1=S.data[S.top];
					S.top--;
					x2=S.data[S.top];
					S. top--;
					result=x2/x1;
					S.top++;
					S.data[S.top]=result;
					break;
			}
			i++;
		}
	}
	//如果栈不空， 将结果出栈并返回
	if(!S.top != -1) {
		result=S.data[S. top];
		S.top--;
		if(S.top == -1)
			return result;
		else{
			return -1024;
		}
	}
	return 0;
}
