#include "../head/LinkStack.h"
#include <stdio.h>
#include <stdlib.h>

Status initLStack(LinkStack *s){
	//printf("%d\n", s);
	if( /*s = (LinkStack *)malloc(sizeof(LinkStack))*/s  ){
		//printf("%d\n", s);
		s->count = 0;
		s->top = NULL;
		return SUCCESS;
	}
	return ERROR;
}

Status isEmptyLStack(LinkStack *s){
	if(s == NULL){
		return ERROR;
	}else{
		if( s->count ){
			return ERROR;
		}else{
			return SUCCESS;
		}
	}
}

Status getTopLStack(LinkStack *s,ElemType *e){
	//printf("111");
	//printf("%d",s->count);
	if(s == NULL || s->count == 0){
		//printf("111");
		return ERROR;
	}else{
		*e = s->top->data;
		//return SUCCESS;
	}
}

Status clearLStack(LinkStack *s){
	if(s == NULL) return ERROR;
	s->count = 0;
	StackNode *p,*q;
	p = s->top;
	while(p != NULL){
		q = p->next;
		free(p);
		p = q;
	}
	return SUCCESS;
}

Status destroyLStack(LinkStack *s){
	StackNode *p,*q;
	p = s->top;
	while(p!=NULL){
		q = p;
		p = p->next;
		free(q);
	}
	s->count = 0;
}

Status LStackLength(LinkStack *s,int *length){
	if(s == NULL) return ERROR;
	*length = s->count;
	return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data){
	if(s == NULL) return ERROR;
	s->count ++;
	StackNode* p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = data;
	p->next = s->top;
	s->top = p;
	
	return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data){
	if(s == NULL || s->count == 0) return ERROR;
	s->count--;
	StackNode *p;
	p = s->top;
	*data = p->data;
	s->top = s->top->next;
	free(p);
	
	return SUCCESS;
}
