#include "../head/SqStack.h"
#include <stdio.h>
#include <stdlib.h>

Status initStack(SqStack *s,int sizes){
	//printf("%d",s);
	
	s = (SqStack *)malloc(sizeof(SqStack));
	//printf("%d",s);
	if(s == NULL ){
		return ERROR;
	}
	
	ElemType stack[sizes] = {0};
	s->elem = stack;
	s->top = s->size = 0; 
	return SUCCESS;

	
	
	
}

Status isEmptyStack(SqStack *s){
	if( s ){
		if(s->size){
			return ERROR; 
		} 
		return SUCCESS;
	}else{
		printf("²éÑ¯Õ»Ê§°Ü£¡");
		return ERROR;
	}
	
}

Status getTopStack(SqStack *s,ElemType *e){
	if(s == NULL || s->size == 0){
		return ERROR;
	}else{
		*e = s->elem[s->top-1];
		return SUCCESS;
	}
}

Status clearStack(SqStack *s){
	if(s == NULL){
		return ERROR;
	}else{
		s->size = s->top = 0;
		return SUCCESS;
	}
}

Status destroyStack(SqStack *s){
	if(s == NULL){
		return ERROR;
	}else{
		//free(s->elem);
//		for(int i = 0;i < s->size;i++){
//			free(s->elem[i]);
//		}
		s->elem = NULL;
		s->size = s->top = 0;
		free(s);
		s = NULL;
		return SUCCESS;
	}
}

Status stackLength(SqStack *s,int *length){
	if(s == NULL){
		return ERROR;
	}else{
		*length = s->size;
		return SUCCESS;
	}
}

Status pushStack(SqStack *s,ElemType data){
	if(s == NULL){
		return ERROR;
	}else{
		s->elem[s->top] = data;
		s->size ++;
		s->top ++;
	}
}

Status popStack(SqStack *s,ElemType *data){
	if(s == NULL || s->size == 0){
		return ERROR;
	}else{
		*data = s->elem[s->top-1];
		s->top --;
		s->size --;
		return SUCCESS;
	}
}




