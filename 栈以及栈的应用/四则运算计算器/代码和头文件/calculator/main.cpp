#include "../head/calculator.h"
#include "../calculator/calculator.c"
int main(){
	char a[MaxSize], b[MaxSize];
	float f;
	printf("��ѡ�����Ĳ�����(ֻ��ȡһ����Чֵ)\n");
	printf("1.����һ���������ʽ\n");
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
				printf("������һ���������ʽ: \n");
				gets(a);
				printf("��׺���ʽΪ�� %s\n", a);
				TranslateExpress(a, b);
				printf("��׺���ʽΪ�� %s\n", b);
				f=ComputeExpress(b);
				if(f != -1024 ){
					printf("�������� %f\n", f);
				}else{
					printf("���ʽ����");
				}
				break;
			RE:
			default:
				printf("����������������룡");
		}
	}
	


	return 0;
}

