#include "../head/LinkStack.h"
#include "../LinkStack/LinkStack.cpp"

int main(){
	LinkStack *s = (LinkStack *)malloc(sizeof(LinkStack));
	int flag = 0;
	ElemType topData;
	int length = 0;
	char arr[100];
	char *p;
	ElemType data;
	
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
	
	while(1){
		char choose;
		char end;
		scanf("%c",&choose);
		scanf("%c",&end);
		if(end != '\n'){
			fflush(stdin);
			goto RE;
		}
		
		switch( choose ){
			case '0':
				printf("�ټ���");
				exit(0);
			case '1':
				//printf("%d\n", &s);
				if( initLStack(s) ){
					printf("��ʼ��ջ�ɹ���\n");
					//printf("%d",s.count);
					flag = 1;
				}else{
					printf("��ʼ��ջʧ�ܣ�\n");
				}
				break;
			case '2':
				if(flag == 1){
					if( isEmptyLStack(s) ){
						printf("ջΪ�գ�\n");
					}else{
						printf("ջ��Ϊ�գ�\n");
					}
				}else{
					printf("���ȳ�ʼ��ջ��\n");
				}
				break;
			case '3':
				if(flag == 1){
					if( getTopLStack(s,&topData) ){
						printf("ջ��Ԫ��Ϊ��%d\n",topData);
					}else{
						printf("��ȡջ��Ԫ��ʧ�ܣ�\n");
					}
				}else{
					printf("���ȳ�ʼ��ջ��\n");
				}
				break;
			case '4':
				if(flag == 1){
					if(clearLStack(s)){
						printf("���ջ�ɹ���\n");
					}else{
						printf("���ջʧ�ܣ�\n");
					}
				}else{
					printf("���ȳ�ʼ��ջ��\n");
				}
				break;
			case '5':
				if(flag == 1){
					if( destroyLStack(s) ){
						printf("����ջ�ɹ���\n");
						flag = 0;
					}else{
						printf("����ջʧ��!\n");
					}
				}else{
					printf("���ȳ�ʼ��ջ��\n");
				}
				break;
			case '6':
				if(flag == 1){
					if( LStackLength(s,&length) ){
						printf("ջ����Ϊ��%d\n",length);
					}else{
						printf("��ȡջ����ʧ�ܣ�\n");
					}
				}else{
					printf("���ȳ�ʼ��ջ��\n");
				}
				break;
			case '7':
				if(flag == 1){
					if( LStackLength(s,&length) ){
						printf("��������ջԪ��:");
						scanf("%s",&arr);
						p = arr;
						while(*p >= '0' && *p <= '9'){
							data = data*10 + *p-'0';
							p++;
						}
						fflush(stdin);
						if( pushLStack(s,data) )	{
							printf("��ջ�ɹ�����ջԪ��Ϊ%d\n",data);
						}else{
							printf("��ջʧ�ܣ�\n");
						}
						data = 0;
					}else{
						printf("��ջʧ�ܣ�\n");
					}
				}else{
					printf("���ȳ�ʼ��ջ��\n");
				}
				break;
			case '8':
				if(flag == 1){
					if( popLStack(s,&topData) ){
						printf("��ջԪ��Ϊ��%d\n",topData);
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
}
