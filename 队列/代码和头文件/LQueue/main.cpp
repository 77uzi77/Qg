#include "../LQueue/LQueue.h"
#include "../LQueue/LQueue.cpp"
int count = -1; 
int main(){
	
	
	printf("请选择您的操作：(只读取一个有效值)\n");
	printf("1.初始化队列\n");
	printf("2.判断队列是否为空\n");
	printf("3.清空队列\n");
	printf("4.销毁队列\n");
	printf("5.检测队列的大小\n");
	printf("6.入队列\n");
	printf("7.出队列\n");
	printf("8.遍历队列\n");
	printf("0.退出\n");
	
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
					printf("初始化队列成功！\n");
				}else{
					printf("队列已经初始化！\n");
				}
				break;
			case '2':
				if(isInit == 1){
					if(IsEmptyLQueue(&Q)){
						printf("队列为空！\n");
					}else{
						printf("队列不为空！\n");
					}
				}else{
					printf("请先初始化队列！\n");
				}
				break;
			case '3':
				if(isInit == 1){
					ClearLQueue(&Q);
					printf("清空队列成功！\n"); 
				}else{
					printf("请先初始化队列！\n");
				}
				break;
			case '4':
				if(isInit == 1){
					DestoryLQueue(&Q);
					printf("销毁队列成功！\n");
					isInit = 0;
				}else{
					printf("请先初始化队列！\n");
				}
				break;
			case '5':
				if(isInit == 1){
					int length = LengthLQueue(&Q);
					printf("队列长度为%d\n",length); 
				}else{
					printf("请先初始化队列！\n");
				}
				break;
			case '6':
				if(isInit == 1){
					DE:
					printf("你想入队哪种类型？:\n");
				    printf("a. 整型 b. 字符型 c. 浮点型d. 字符串\n");
				    scanf("%c", &f);
					char last;
					scanf("%c",&last);
					if(last != '\n'){
						fflush(stdin);
						goto DE;
					}
					printf("请输入想入队的数据 :");
					//printf("%c",type);
					//printf("count = %d\n",count);
				    if(f=='a' ){
			     		scanf("%d", &a);
						dataType[count++]=f;
						EnLQueue(&Q, &a);
						printf("输入成功！\n");
					
					}		
					if(f == 'b'){
						scanf("%c", &b);
						dataType[count++]=f;
						EnLQueue(&Q, &b);
						printf("输入成功！\n");
					}
					if(f == 'c'){
						scanf("%lf", &c);
						dataType[count++]=f;
						EnLQueue(&Q, &c);
						printf("输入成功！\n");
					}	
					if(f == 'd'){
						printf("最大长度为20哦！\n");
						scanf("%s", d);
						dataType[count++]=f;
						EnLQueue(&Q, d);
						printf("输入成功！\n");
					}	
					getchar();		
				}else{
					printf("请先初始化队列！\n");
				}
				break;
			case '7':
				if(isInit == 1){
					if(DeLQueue(&Q)){
						printf("出队成功！\n");
					}else{
						printf("出队失败！\n");
					}
				}else{
					printf("请先初始化队列！\n");
				}
				break;
			case '8':
				if(isInit == 1){
					TraverseLQueue(&Q, LPrint);
					printf("\n");
				}else{
					printf("请先初始化队列！\n");
				}
				break;
			case '0':
				exit(0);
			RE:
			default :
				printf("输入错误！请重新输入！\n");
				break;	
		} 
	} 
	return 0;
}
