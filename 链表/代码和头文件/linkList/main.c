#include "../head/linkedList.h"
#include "../linkList/linkedList.c"
int main(){
	
	int input;
	int flag;
	ElemType case3Input;
	ElemType case4DelValue;
	ElemType case6Input;
	ElemType NodeData;
	LinkedList L = NULL; 
	LinkedList EvenL = NULL;
	LinkedList tmp = NULL;
	LinkedList midNode = NULL;
	//void (*p)(int a);
	//p = &visit;
	
	printf("您想进行的操作是：\n");
	printf("1.生成链表\n");
	printf("2.销毁链表\n");
	printf("3.插入节点(头插法)\n");
	printf("4.删除节点（第一个）\n");
	printf("5.遍历链表\n");
	printf("6.查找数值\n");
	printf("7.反转链表\n");
	printf("8.判断链表是否有环\n");
	printf("9.单链表奇偶调换\n");
	printf("10.找到链表的中间节点\n"); 
	printf("0.退出\n"); 
		
	while(1){
		
        while (1)
		{
			scanf("%d",&input);
			while (getchar() != '\n');
			if ( input>=0 && input<=10)
			{
				break;
			} 
			puts("请输入一个有效的值!\n");
		}		
             
		switch( input ){
			case 0:
				exit(0);
				break;
			case 1:
				flag = InitList(&L);
				if( flag == SUCCESS )
					printf("生成链表成功\n");
				else
					printf("生成链表失败\n");
				break;
			case 2:
				DestroyList(&L);
				printf("销毁链表成功\n");
				break;
			case 3:
				printf("请输入你想插入的值(整数)：");
				scanf("%d",&case3Input);
				tmp = (LinkedList)malloc(sizeof(LNode));
				tmp->data = case3Input;
				tmp->next = NULL;
				flag = InsertList(L, tmp);
				if( flag == SUCCESS )
					printf("插入成功\n"); 
				else
					printf("插入失败\n"); 
				//free(tmp);
				//printf("%d", L->next->data);
				break;
			case 4:
				flag = DeleteList(L, &case4DelValue);
				if( flag == SUCCESS )
					printf("删除成功\n删除节点的值为%d",case4DelValue);
				else
					printf("删除失败\n");
				break;
			case 5:
				TraverseList(L);
				break;
			case 6:
				printf("请输入你想查找的值(整数)：");
				scanf("%d",&case6Input);
				flag = SearchList(L,case6Input);
				if(flag == SUCCESS)
					printf("查找成功\n");
				else 
					printf("查找失败\n");
				break; 
			case 7:
				flag = ReverseList(L); 
				if(flag == SUCCESS)
					printf("反转链表成功\n");
				else
					printf("反转链表失败\n");
				break;
			case 8:
				flag = IsLoopList(L);
				if(flag == SUCCESS)
					printf("链表有环\n");
				else
					printf("链表无环\n");
				break;
			case 9:
				EvenL = ReverseEvenList(L);
				printf("调换成功\n调换后的链表为：");
				TraverseList( EvenL );
				break;
			case 10:
			    midNode = (LinkedList)malloc(sizeof(LNode));
				midNode = FindMidNode(&L);
				printf("中间节点的值为%d\n",midNode->data);
				break;
			default:
				printf("输入有误！请重新输入");
				break;
		}
	}
} 

