#include "../head/SqStack.h"
#include "../SqStack/SqStack.cpp"

int main(){
	SqStack s;
	int sizes;
	ElemType StackTop = 0;
	int length = 0;
	char arr[100];
	char *p;
	ElemType data = 0;
	ElemType outPut;
	int isInit = 0;
	
	printf("��ѡ�����Ĳ�����(ֻ��ȡһ����Чֵ)\n");
	printf("1.��ʼ��ջ\n");
	printf("2.�ж�ջ�Ƿ�Ϊ��\n");
	printf("3.�õ�ջ��Ԫ��\n");
	printf("4.���ջ\n");
	printf("5.����ջ\n");
	printf("6.���ջ�Ĵ�С\n");
	printf("7.��ջ\n");
	printf("8.��ջ\n");
	printf("0.�˳�\n");
	
	while(1)
	{
		char choose;
		char end;
		scanf("%c",&choose);
		scanf("%c",&end);
		if(end != '\n'){
			fflush(stdin);
			goto RE;
		}
		//printf("%c",choose);
		switch( choose ){
			case '0':
				printf("�ټ���");
				exit(0);
			case '1':
				while(1){
					if(isInit == 0){
						sizes = 0;
						printf("������ջ�Ĵ�С��");
						scanf("%d",&sizes);
						fflush(stdin);
						//printf("%d",case1Input);
						if(sizes > 0 ){
							if( initStack(&s,sizes) ){
								printf("��ʼ��ջ�ɹ���\n");
								isInit = 1;
								isInit = 1;
								break;
							}else{
								printf("��ʼ��ջʧ�ܣ�\n");
							}
						}else{
							printf("��������ȷ�Ĵ�С��\n");
						}
					}else{
							printf("ջ�Ѿ���ʼ����\n");
							break;
						}		
				}
				break;
			case '2':
				if(isInit == 1){
					if(isEmptyStack(&s)){
						printf("ջΪ�գ�\n");
					}else{
						printf("ջ��Ϊ�գ�\n");
					}
				}else{
					printf("���ȳ�ʼ��ջ��\n");
				}
				break;
			case '3':
				if(isInit == 1){
					if( getTopStack(&s,&StackTop) ){
						printf("ջ��Ԫ��Ϊ��%d\n",StackTop);
					}else{
						printf("��ȡջ��Ԫ��ʧ�ܣ�\n");
					}
				}else{
					printf("���ȳ�ʼ��ջ��\n");
				}
				break;
			case '4':
				if(isInit == 1){
					if( clearStack(&s) ){
						printf("���ջ�ɹ���\n");
					}else{
						printf("���ջʧ�ܣ�\n");
					}
				}else{
					printf("���ȳ�ʼ��ջ��\n");
				}
				break;
			case '5':
				if(isInit == 1){
					if( destroyStack(&s) ){
						printf("����ջ�ɹ���\n");
						isInit = 0;
						isInit = 0;
					}else{
						printf("����ջʧ�ܣ�\n");
					}
				}else{
					printf("���ȳ�ʼ��ջ��\n");
				}
				break;
			case '6':
				if(isInit == 1){
					if( stackLength(&s,&length) ){
						printf("ջ�ĳ���Ϊ��%d\n",length);
					}else{
						printf("��ȡջ����ʧ�ܣ�\n");
					}
				}else{
					printf("���ȳ�ʼ��ջ��\n");
				}
				break;
			case '7':
				if(isInit == 1){
					if( stackLength(&s,&length) ){
						if( length <= sizes ){
							printf("��������ջԪ��:");
							scanf("%s",&arr);
							p = arr;
							while(*p >= '0' && *p <= '9'){
								data = data*10 + *p-'0';
								p++;
							}
							fflush(stdin);
							if( pushStack(&s,data) )	{
								printf("��ջ�ɹ�����ջԪ��Ϊ%d\n",data);
							}else{
								printf("��ջʧ�ܣ�\n");
							}
							data = 0;
						}else{
							printf("ջ����!\n");
						}
					}else{
						printf("��ջʧ�ܣ�\n");
					}
				}else{
					printf("���ȳ�ʼ��ջ��\n");
				}
				break;
			case '8':
				if(isInit == 1){
					if( popStack(&s,&outPut) ){
						printf("��ջԪ��Ϊ:%d\n",outPut);
					}else{
						printf("��ջʧ�ܣ�\n");
					}
				}else{
					printf("���ȳ�ʼ��ջ��\n");
				}
				break;
			RE:
			default :
				printf("����������������룡\n");
				break;
		}
	}
	
	return 0;
}
