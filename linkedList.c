#include "../head/linkedList.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
// // define element type
//typedef int ElemType;
//
//// define struct of linked list
//typedef struct LNode {
//	ElemType data;
//  	struct LNode *next;
//} LNode, *LinkedList;
//
//// define Status
//typedef enum Status {
//	ERROR,
//	SUCCESS
//} Status;
//

Status InitList(LinkedList *L) {
	
	*L = (LinkedList)malloc(sizeof(LinkedList) );
	
	if( *L == NULL ){
		printf("分配内存失败！");
		return ERROR;
	}
	(*L)->next = NULL;
	
	return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LNode *p = *L;
    while( p ){
    	p = p->next;
    	free(*L);
    	*L = p;
	}
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	if(p==NULL || q==NULL) return ERROR;
	q->next = p->next;
	p->next = q;
	return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	if(p == NULL || p->next == NULL) return ERROR;
	LNode *q = p->next;
	*e = q->data;
	p->next = q->next;
	free(q);
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L) {
	
	LNode *p = L->next;
	while(p){
		visit(p->data); 
		p=p->next;
	}
	printf("\n");
}

void visit(ElemType e){
	printf("%d ",e);
}
/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	if(L->next == NULL) return ERROR;
	LNode *p = L->next;
	while(p != NULL){
		if(p->data == e){
			return SUCCESS;
		}
		p = p->next;
	}
	return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList L) {
	if(L == NULL){
		return ERROR;
	}
	LNode *First,*Mid,*Last;
	Mid = L->next;
	L->next = NULL;
	First = Last = NULL;
	while( Mid ){
		Last = Mid->next;
		Mid->next = First;
		First = Mid;
		Mid = Last;
	}
	L->next = First;
	
	return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	if(L == NULL || L->next == NULL) return ERROR;
	LNode *fast,*slow;
	fast = slow = L;
	
 	while( fast != NULL && fast->next != NULL)  
    {  
  		
        fast = fast->next->next;  
        slow = slow->next;  
        //如果有环，则fast会超过slow一圈  
        if(fast == slow)  
        {  
            return SUCCESS;  
        }  
    }  
  	return ERROR;
	
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList L) {
//	if( L == NULL || L->next == NULL) return L;
//	LNode *p,*tmp,*r;
//	p = L;
//	
//	r = p->next;
//	while( r!= NULL && r->next!=NULL ){
//		tmp = p->next;
//		p->next = r->next;
//		r->next = r->next->next;
//		p->next->next = tmp;
//		p = p->next;
//		r = r->next;
//	}
//	return L;
	if( L == NULL || L->next == NULL) return L;
	LNode *p,*tmp,*r,*t;
	tmp = L;
	p = L->next;
    r = p->next;
	while( r!=NULL ){
		if(r->data%2 == 0){
			p->next = r->next;
			r->next = p;
			tmp->next = r;
			t = p;
			p = r;
			r = t;	
		}
		tmp = tmp->next;	
		p=p->next;
		r=r->next;
	} 
	return L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
	if( (*L) == NULL || (*L)->next == NULL) return *L;
	LNode *fast,*slow;
	fast = slow = *L;
	while(fast != NULL){
		if(fast->next == NULL) fast = fast->next;
		else{
			fast = fast->next->next;
		}
		slow = slow->next;
	}
	return slow;
}

