#include "../LQueue/LQueue.h"
extern int count; 

void InitLQueue(LQueue *Q) {
	Node *p = (Node *)malloc(sizeof(Node));
	if (NULL == p)
		return;
	p->next = NULL;
	Q->front = p;
	Q->rear = p;
	count = 0;
	return;
}


void DestoryLQueue(LQueue *Q) {
	if (IsEmptyLQueue(Q))
		return; 
	ClearLQueue(Q);
	free(Q->front);
	free(Q->rear);
	count = 0;
}


Status IsEmptyLQueue(const LQueue *Q) {
	return (Q->front == Q->rear? TRUE: FALSE);
}


Status GetHeadLQueue(LQueue *Q, void *e) {
	if (IsEmptyLQueue(Q))
		return FALSE;
	memcpy(e, Q->front->next->data, 20);//在头结点下一个节点指向的位置赋予字节数 
	return TRUE;	
}


int LengthLQueue(LQueue *Q) {
	int length;
	Node *p = (Node *)malloc(sizeof(Node));
	p = Q->front;
	for (length = 0; p != Q->rear; length++)
		p = p->next; 
	return length;
} 


Status EnLQueue(LQueue *Q, void *data) {
	Node *p = (Node *)malloc(sizeof(Node));
	if (NULL == p)
		return FALSE;
	p->data = (void *)malloc(20);
	memcpy(p->data, data, 20);
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;	
//	count++;
	return TRUE;

}	


Status DeLQueue(LQueue *Q) {
	if(IsEmptyLQueue(Q))
		return FALSE;
	Node *p = (Node *)malloc(sizeof(Node));
	p = Q->front->next;
	Q->front->next = p->next;
	if (NULL == Q->front->next)  
		Q->rear = Q->front;
	free(p);	
	count--;
	return TRUE;
}


void ClearLQueue(LQueue *Q) {
	if (IsEmptyLQueue(Q))
		return;
	Node *p, *q;
	Q->rear = Q->front;
	p = Q->front->next; 
	while (NULL != p) {
		q = p;
		p = p->next;
		free(q);
	}
	free(p);	
	count = 0;
	return;
}	


//foo利用Lprint打印函数 

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q,char type)) {
	if (IsEmptyLQueue(Q))
		return FALSE;
		//Node* p = (void *)malloc(20); 
		Node* p = (Node*)malloc(20); 		
		p = Q->front->next; 
		int i = 1;
		count = 0;
		while (p != NULL) {
			if (i % 5 == 0) printf("\n"); 			
			foo(p->data, dataType[count++]);
			p = p->next;
			i++;
		}
		printf("\n");
	return TRUE;
}


//根据类型遍历 

void LPrint(void *q, char type) {
	if (type == 'a'){
		printf("%d  ", *(int *)q);
	}
	
	if (type == 'b'){
		printf("%c ", *(char *)q);
	}
			
	if (type == 'c'){
		printf("%.2lf ", *(double *)q);
	}

	if(type == 'd'){
		printf("%s ",(char *)q);
	}
}



