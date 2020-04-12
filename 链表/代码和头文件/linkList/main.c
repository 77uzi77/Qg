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
	
	printf("������еĲ����ǣ�\n");
	printf("1.��������\n");
	printf("2.��������\n");
	printf("3.����ڵ�(ͷ�巨)\n");
	printf("4.ɾ���ڵ㣨��һ����\n");
	printf("5.��������\n");
	printf("6.������ֵ\n");
	printf("7.��ת����\n");
	printf("8.�ж������Ƿ��л�\n");
	printf("9.��������ż����\n");
	printf("10.�ҵ�������м�ڵ�\n"); 
	printf("0.�˳�\n"); 
		
	while(1){
		
        while (1)
		{
			scanf("%d",&input);
			while (getchar() != '\n');
			if ( input>=0 && input<=10)
			{
				break;
			} 
			puts("������һ����Ч��ֵ!\n");
		}		
             
		switch( input ){
			case 0:
				exit(0);
				break;
			case 1:
				flag = InitList(&L);
				if( flag == SUCCESS )
					printf("��������ɹ�\n");
				else
					printf("��������ʧ��\n");
				break;
			case 2:
				DestroyList(&L);
				printf("��������ɹ�\n");
				break;
			case 3:
				printf("��������������ֵ(����)��");
				scanf("%d",&case3Input);
				tmp = (LinkedList)malloc(sizeof(LNode));
				tmp->data = case3Input;
				tmp->next = NULL;
				flag = InsertList(L, tmp);
				if( flag == SUCCESS )
					printf("����ɹ�\n"); 
				else
					printf("����ʧ��\n"); 
				//free(tmp);
				//printf("%d", L->next->data);
				break;
			case 4:
				flag = DeleteList(L, &case4DelValue);
				if( flag == SUCCESS )
					printf("ɾ���ɹ�\nɾ���ڵ��ֵΪ%d",case4DelValue);
				else
					printf("ɾ��ʧ��\n");
				break;
			case 5:
				TraverseList(L);
				break;
			case 6:
				printf("������������ҵ�ֵ(����)��");
				scanf("%d",&case6Input);
				flag = SearchList(L,case6Input);
				if(flag == SUCCESS)
					printf("���ҳɹ�\n");
				else 
					printf("����ʧ��\n");
				break; 
			case 7:
				flag = ReverseList(L); 
				if(flag == SUCCESS)
					printf("��ת����ɹ�\n");
				else
					printf("��ת����ʧ��\n");
				break;
			case 8:
				flag = IsLoopList(L);
				if(flag == SUCCESS)
					printf("�����л�\n");
				else
					printf("�����޻�\n");
				break;
			case 9:
				EvenL = ReverseEvenList(L);
				printf("�����ɹ�\n�����������Ϊ��");
				TraverseList( EvenL );
				break;
			case 10:
			    midNode = (LinkedList)malloc(sizeof(LNode));
				midNode = FindMidNode(&L);
				printf("�м�ڵ��ֵΪ%d\n",midNode->data);
				break;
			default:
				printf("������������������");
				break;
		}
	}
} 

