#include "../head/calculator.h"
#include "../calculator/calculator.c"
int main(){
	char a[MaxSize], b[MaxSize];
	float f;
	printf("请选择您的操作：(只读取一个有效值)\n");
	printf("1.计算一个整数表达式\n");
	printf("0.退出\n");
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
				printf("再见！");
				exit(0);
			case '1':
				printf("请输入一个整数表达式: \n");
				gets(a);
				printf("中缀表达式为： %s\n", a);
				TranslateExpress(a, b);
				printf("后缀表达式为： %s\n", b);
				f=ComputeExpress(b);
				if(f != -1024 ){
					printf("计算结果： %f\n", f);
				}else{
					printf("表达式错误！");
				}
				break;
			RE:
			default:
				printf("输入错误！请重新输入！");
		}
	}
	


	return 0;
}

