#include "../head/duLinkedList.h"
#include "../duLinkList/duLinkedList.c"
int main(){
	
	int input;
	int status;
	ElemType case3Input;
	ElemType case4Input;
	ElemType case5Value;
	DuLinkedList L;
	DuLinkedList beforeNode;
	DuLinkedList afterNode;
	
	printf("您想进行的操作是：\n");
	printf("1.生成链表\n");
	printf("2.销毁链表\n");
	printf("3.插入节点(向前插)\n");
	printf("4.插入节点（向后插）\n");
	printf("5.删除节点\n");
	printf("6.遍历链表\n");
	printf("0.退出\n"); 
		
	while(1){
		
		  while (1)
		{
			scanf("%d",&input);
			while (getchar() != '\n');
			if ( input>=0 && input<=6)
			{
				break;
			} 
			puts("请输入一个有效的值!\n");
		}	
		
		switch(input){
			case 0:
				exit(0);
			case 1:
				if( InitList_DuL(&L) )
					printf("初始化成功！\n");
				else
					printf("初始化失败！\n");
				break;
			case 2:
				DestroyList_DuL(&L);
				printf("销毁双向链表成功！\n");
				break;
			case 3:
				printf("请输入你想插入的值(整数)：");
				scanf("%d",&case3Input);
				beforeNode = (DuLinkedList)malloc(sizeof(DuLNode));
				beforeNode->data = case3Input; 
				beforeNode->next = NULL;
				beforeNode->prior = NULL;
				status = InsertBeforeList_DuL(L,beforeNode);
				if( status == SUCCESS  )
					printf("插入成功！\n");
				else
					printf("插入失败！\n");
				break;
			case 4:
				printf("请输入你想插入的值(整数)：");
				scanf("%d",&case4Input);
				afterNode = (DuLinkedList)malloc(sizeof(DuLNode));
				afterNode->data = case4Input; 
				status =  InsertAfterList_DuL(L, afterNode );
				if( status == SUCCESS) 
					printf("插入成功！\n");
				else
					printf("插入失败！\n");
				break;
			case 5:
				status = DeleteList_DuL(L, &case5Value);
				if( status == SUCCESS )
					printf("删除成功！删除节点的值为%d\n",case5Value);
				else
					printf("删除失败！\n");
				break;
			case 6:
				TraverseList_DuL( L );
				break;
			default:
				printf("输入有误！请重新输入");
				break;
				
		}
	}
	
	
	return 0;
}
