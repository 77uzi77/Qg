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
	
	printf("请选择您的操作：(只读取一个有效值)\n");
	printf("1.初始化栈\n");
	printf("2.判断栈是否为空\n");
	printf("3.得到栈顶元素\n");
	printf("4.清空栈\n");
	printf("5.销毁栈\n");
	printf("6.检测栈的大小\n");
	printf("7.入栈\n");
	printf("8.出栈\n");
	printf("0.退出\n");
	
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
				printf("再见！");
				exit(0);
			case '1':
				while(1){
					if(isInit == 0){
						sizes = 0;
						printf("请输入栈的大小：");
						scanf("%d",&sizes);
						fflush(stdin);
						//printf("%d",case1Input);
						if(sizes > 0 ){
							if( initStack(&s,sizes) ){
								printf("初始化栈成功！\n");
								isInit = 1;
								isInit = 1;
								break;
							}else{
								printf("初始化栈失败！\n");
							}
						}else{
							printf("请输入正确的大小！\n");
						}
					}else{
							printf("栈已经初始化！\n");
							break;
						}		
				}
				break;
			case '2':
				if(isInit == 1){
					if(isEmptyStack(&s)){
						printf("栈为空！\n");
					}else{
						printf("栈不为空！\n");
					}
				}else{
					printf("请先初始化栈！\n");
				}
				break;
			case '3':
				if(isInit == 1){
					if( getTopStack(&s,&StackTop) ){
						printf("栈顶元素为：%d\n",StackTop);
					}else{
						printf("获取栈顶元素失败！\n");
					}
				}else{
					printf("请先初始化栈！\n");
				}
				break;
			case '4':
				if(isInit == 1){
					if( clearStack(&s) ){
						printf("清空栈成功！\n");
					}else{
						printf("清空栈失败！\n");
					}
				}else{
					printf("请先初始化栈！\n");
				}
				break;
			case '5':
				if(isInit == 1){
					if( destroyStack(&s) ){
						printf("销毁栈成功！\n");
						isInit = 0;
						isInit = 0;
					}else{
						printf("销毁栈失败！\n");
					}
				}else{
					printf("请先初始化栈！\n");
				}
				break;
			case '6':
				if(isInit == 1){
					if( stackLength(&s,&length) ){
						printf("栈的长度为：%d\n",length);
					}else{
						printf("获取栈长度失败！\n");
					}
				}else{
					printf("请先初始化栈！\n");
				}
				break;
			case '7':
				if(isInit == 1){
					if( stackLength(&s,&length) ){
						if( length <= sizes ){
							printf("请输入入栈元素:");
							scanf("%s",&arr);
							p = arr;
							while(*p >= '0' && *p <= '9'){
								data = data*10 + *p-'0';
								p++;
							}
							fflush(stdin);
							if( pushStack(&s,data) )	{
								printf("入栈成功，入栈元素为%d\n",data);
							}else{
								printf("入栈失败！\n");
							}
							data = 0;
						}else{
							printf("栈已满!\n");
						}
					}else{
						printf("入栈失败！\n");
					}
				}else{
					printf("请先初始化栈！\n");
				}
				break;
			case '8':
				if(isInit == 1){
					if( popStack(&s,&outPut) ){
						printf("出栈元素为:%d\n",outPut);
					}else{
						printf("出栈失败！\n");
					}
				}else{
					printf("请先初始化栈！\n");
				}
				break;
			RE:
			default :
				printf("输入错误！请重新输入！\n");
				break;
		}
	}
	
	return 0;
}
