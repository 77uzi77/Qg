#include "../head/calculator.h"


void InitStack(SeqStack *S) //��ʼ��ջ
{
	S->top = 0;
}

int StackEmpty(SeqStack S) //�ж�ջ�Ƿ�Ϊ��
{
	if(S.top == 0) 
	return 1;
	else 
	return 0;
}
int PushStack(SeqStack *S, char e) //��ջ
{
	if(S->top >= MaxSize)
	{
		printf("ջ������ ���ܽ�ջ!") ;
		return 0;
	}
	else
	{
		S->data[S->top] = e;
		S->top++;
		return 1;
	}
}
int PopStack(SeqStack *S, char *e) //ɾ��ջ��Ԫ��
{
	if(S->top == 0){
		printf("ջ�ѿ�\n") ;
		return 0;
	}
	else{
		S->top--;
		*e = S->data[S->top];
		return 1;
	}
}
int GetTop(SeqStack S, char *e) //ȡջ��Ԫ��
{
	if(S.top <= 0){
		printf("ջ�ѿ�") ;
		return 0;
	}
	else{
		*e = S.data[S.top-1];
		return 1;
	}
}

//����׺���ʽת��Ϊ��׺���ʽ
void TranslateExpress(char str[], char exp[]) 
{
	SeqStack S;
	char ch;
	char e;
	int i=0, j=0;
	InitStack(&S);
	ch=str[i];
	i++;
	//����ɨ����׺���ʽ
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
				//�ǿո�ͺ���
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
	//��ջ��ʣ���������ջ
	while(!StackEmpty(S) ) {
		PopStack(&S, &e) ;
		exp[j]=e;
		j++;
	}
	exp[j]='\0';
}

//�����׺���ʽ��ֵ
float ComputeExpress(char a[]) {
	
	OpStack S;
	int i=0;
	float x1, x2, value;
	float result;
	S.top=-1;
	//����ɨ���׺���ʽ
	while(a[i]!='\0' ) {
		//���������
		if(a[i]!=' ' &&a[i]>='0' &&a[i]<='9' ) {
			value=0;
			//������ǿո�
			while(a[i]!=' ' ) {
				value=10*value+a[i]-'0';
				i++;
			}
			S.top++;
			S.data[S.top]=value; 
		}
		//����������
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
	//���ջ���գ� �������ջ������
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
