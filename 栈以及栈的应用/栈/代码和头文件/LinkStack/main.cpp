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
				//printf("%d\n", &s);
				if( initLStack(s) ){
					printf("初始化栈成功！\n");
					//printf("%d",s.count);
					flag = 1;
				}else{
					printf("初始化栈失败！\n");
				}
				break;
			case '2':
				if(flag == 1){
					if( isEmptyLStack(s) ){
						printf("栈为空！\n");
					}else{
						printf("栈不为空！\n");
					}
				}else{
					printf("请先初始化栈！\n");
				}
				break;
			case '3':
				if(flag == 1){
					if( getTopLStack(s,&topData) ){
						printf("栈顶元素为：%d\n",topData);
					}else{
						printf("获取栈顶元素失败！\n");
					}
				}else{
					printf("请先初始化栈！\n");
				}
				break;
			case '4':
				if(flag == 1){
					if(clearLStack(s)){
						printf("清空栈成功！\n");
					}else{
						printf("清空栈失败！\n");
					}
				}else{
					printf("请先初始化栈！\n");
				}
				break;
			case '5':
				if(flag == 1){
					if( destroyLStack(s) ){
						printf("销毁栈成功！\n");
						flag = 0;
					}else{
						printf("销毁栈失败!\n");
					}
				}else{
					printf("请先初始化栈！\n");
				}
				break;
			case '6':
				if(flag == 1){
					if( LStackLength(s,&length) ){
						printf("栈长度为：%d\n",length);
					}else{
						printf("获取栈长度失败！\n");
					}
				}else{
					printf("请先初始化栈！\n");
				}
				break;
			case '7':
				if(flag == 1){
					if( LStackLength(s,&length) ){
						printf("请输入入栈元素:");
						scanf("%s",&arr);
						p = arr;
						while(*p >= '0' && *p <= '9'){
							data = data*10 + *p-'0';
							p++;
						}
						fflush(stdin);
						if( pushLStack(s,data) )	{
							printf("入栈成功，入栈元素为%d\n",data);
						}else{
							printf("入栈失败！\n");
						}
						data = 0;
					}else{
						printf("入栈失败！\n");
					}
				}else{
					printf("请先初始化栈！\n");
				}
				break;
			case '8':
				if(flag == 1){
					if( popLStack(s,&topData) ){
						printf("出栈元素为：%d\n",topData);
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
}
