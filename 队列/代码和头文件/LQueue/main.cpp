#include "../LQueue/LQueue.h"
#include "../LQueue/LQueue.cpp"
int count = -1; 
int main(){
	
	
	printf("��ѡ�����Ĳ�����(ֻ��ȡһ����Чֵ)\n");
	printf("1.��ʼ������\n");
	printf("2.�ж϶����Ƿ�Ϊ��\n");
	printf("3.��ն���\n");
	printf("4.���ٶ���\n");
	printf("5.�����еĴ�С\n");
	printf("6.�����\n");
	printf("7.������\n");
	printf("8.��������\n");
	printf("0.�˳�\n");
	
	LQueue Q;
	int isInit = 0;
	int e;
	int data;
	char input[100];
	char *p;
	
	int a;
	char b;
	double c;
	char d[16];
	char f;

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
			case '1': 
				if( isInit == 0){
					InitLQueue(&Q);
					isInit = 1;
					printf("��ʼ�����гɹ���\n");
				}else{
					printf("�����Ѿ���ʼ����\n");
				}
				break;
			case '2':
				if(isInit == 1){
					if(IsEmptyLQueue(&Q)){
						printf("����Ϊ�գ�\n");
					}else{
						printf("���в�Ϊ�գ�\n");
					}
				}else{
					printf("���ȳ�ʼ�����У�\n");
				}
				break;
			case '3':
				if(isInit == 1){
					ClearLQueue(&Q);
					printf("��ն��гɹ���\n"); 
				}else{
					printf("���ȳ�ʼ�����У�\n");
				}
				break;
			case '4':
				if(isInit == 1){
					DestoryLQueue(&Q);
					printf("���ٶ��гɹ���\n");
					isInit = 0;
				}else{
					printf("���ȳ�ʼ�����У�\n");
				}
				break;
			case '5':
				if(isInit == 1){
					int length = LengthLQueue(&Q);
					printf("���г���Ϊ%d\n",length); 
				}else{
					printf("���ȳ�ʼ�����У�\n");
				}
				break;
			case '6':
				if(isInit == 1){
					DE:
					printf("��������������ͣ�:\n");
				    printf("a. ���� b. �ַ��� c. ������d. �ַ���\n");
				    scanf("%c", &f);
					char last;
					scanf("%c",&last);
					if(last != '\n'){
						fflush(stdin);
						goto DE;
					}
					printf("����������ӵ����� :");
					//printf("%c",type);
					//printf("count = %d\n",count);
				    if(f=='a' ){
			     		scanf("%d", &a);
						dataType[count++]=f;
						EnLQueue(&Q, &a);
						printf("����ɹ���\n");
					
					}		
					if(f == 'b'){
						scanf("%c", &b);
						dataType[count++]=f;
						EnLQueue(&Q, &b);
						printf("����ɹ���\n");
					}
					if(f == 'c'){
						scanf("%lf", &c);
						dataType[count++]=f;
						EnLQueue(&Q, &c);
						printf("����ɹ���\n");
					}	
					if(f == 'd'){
						printf("��󳤶�Ϊ20Ŷ��\n");
						scanf("%s", d);
						dataType[count++]=f;
						EnLQueue(&Q, d);
						printf("����ɹ���\n");
					}	
					getchar();		
				}else{
					printf("���ȳ�ʼ�����У�\n");
				}
				break;
			case '7':
				if(isInit == 1){
					if(DeLQueue(&Q)){
						printf("���ӳɹ���\n");
					}else{
						printf("����ʧ�ܣ�\n");
					}
				}else{
					printf("���ȳ�ʼ�����У�\n");
				}
				break;
			case '8':
				if(isInit == 1){
					TraverseLQueue(&Q, LPrint);
					printf("\n");
				}else{
					printf("���ȳ�ʼ�����У�\n");
				}
				break;
			case '0':
				exit(0);
			RE:
			default :
				printf("����������������룡\n");
				break;	
		} 
	} 
	return 0;
}
