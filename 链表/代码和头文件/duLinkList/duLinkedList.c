#include "../head/duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	*L = (DuLinkedList)malloc(sizeof(DuLNode)); 
	if(*L == NULL){
		printf("·ÖÅäÄÚ´æÊ§°Ü£¡");
		return ERROR;
	}
	(*L)->prior = (*L)->next = (*L);
	
	
	return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLNode *p = (*L);
	while(p!= NULL){
		p = p->next;
		free((*L));
		*L = p;
	}
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	if(p == NULL || q == NULL){
		return ERROR;
	}
	q->prior = p;
	q->next = p->next;
	p->next->prior = q;
	p->next = q;

	
	return SUCCESS; 
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	if(p == NULL || q == NULL ){
		return ERROR;
	}
	q->next = p;
	q->prior = p->prior;
	p->prior->next = q;
	p->prior = q;

	return SUCCESS;	
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	if(p == NULL || p->next== NULL){
		return ERROR;
	}
	DuLNode* q = p->next;
	*e = p->next->data;
	p->next = p->next->next;
	p->next->next->prior = p;
	free(q);
	return SUCCESS;
	
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L ) {
	DuLNode *p = L->next;
	while(p!=L)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	
}

void visit(ElemType e){
	printf("%d ",e);
}
