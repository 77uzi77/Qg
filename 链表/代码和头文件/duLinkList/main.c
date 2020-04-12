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
	
	printf("������еĲ����ǣ�\n");
	printf("1.��������\n");
	printf("2.��������\n");
	printf("3.����ڵ�(��ǰ��)\n");
	printf("4.����ڵ㣨���壩\n");
	printf("5.ɾ���ڵ�\n");
	printf("6.��������\n");
	printf("0.�˳�\n"); 
		
	while(1){
		
		  while (1)
		{
			scanf("%d",&input);
			while (getchar() != '\n');
			if ( input>=0 && input<=6)
			{
				break;
			} 
			puts("������һ����Ч��ֵ!\n");
		}	
		
		switch(input){
			case 0:
				exit(0);
			case 1:
				if( InitList_DuL(&L) )
					printf("��ʼ���ɹ���\n");
				else
					printf("��ʼ��ʧ�ܣ�\n");
				break;
			case 2:
				DestroyList_DuL(&L);
				printf("����˫������ɹ���\n");
				break;
			case 3:
				printf("��������������ֵ(����)��");
				scanf("%d",&case3Input);
				beforeNode = (DuLinkedList)malloc(sizeof(DuLNode));
				beforeNode->data = case3Input; 
				beforeNode->next = NULL;
				beforeNode->prior = NULL;
				status = InsertBeforeList_DuL(L,beforeNode);
				if( status == SUCCESS  )
					printf("����ɹ���\n");
				else
					printf("����ʧ�ܣ�\n");
				break;
			case 4:
				printf("��������������ֵ(����)��");
				scanf("%d",&case4Input);
				afterNode = (DuLinkedList)malloc(sizeof(DuLNode));
				afterNode->data = case4Input; 
				status =  InsertAfterList_DuL(L, afterNode );
				if( status == SUCCESS) 
					printf("����ɹ���\n");
				else
					printf("����ʧ�ܣ�\n");
				break;
			case 5:
				status = DeleteList_DuL(L, &case5Value);
				if( status == SUCCESS )
					printf("ɾ���ɹ���ɾ���ڵ��ֵΪ%d\n",case5Value);
				else
					printf("ɾ��ʧ�ܣ�\n");
				break;
			case 6:
				TraverseList_DuL( L );
				break;
			default:
				printf("������������������");
				break;
				
		}
	}
	
	
	return 0;
}
