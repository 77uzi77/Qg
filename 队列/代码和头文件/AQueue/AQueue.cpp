#include "../AQueue/AQueue.h"
extern int count;

void InitAQueue(AQueue *Q)
{
    int i;
	Q->length = MAXQUEUE;
    for(i = 0; i < MAXQUEUE; i++)
        //不知道用户想放入的数据类型大小，所以给个20
        Q->data[i] = (void *)malloc(21);
	Q->front = Q->rear = 0;
	count = Q->rear;
}


void DestoryAQueue(AQueue *Q)
{

	for(int i = 0; i < MAXQUEUE; i++)
        free(Q->data[i]);
	Q->data[0] = NULL;
}



Status IsFullAQueue(const AQueue *Q)
{

    if(IsEmptyAQueue(Q))
        return FALSE;
    if(LengthAQueue(Q)==MAXQUEUE-1)
    {
        return TRUE;
    }
    else
        return FALSE;
}


Status IsEmptyAQueue(const AQueue *Q)
{

	return (LengthAQueue(Q) == 0 ? TRUE : FALSE);
}



Status GetHeadAQueue(AQueue *Q, void *e)
{
	if (IsEmptyAQueue(Q))
	{
		printf("队列为空！没有队头！\n");
		return FALSE;
	}
	memcpy(e, Q->data[Q->front],20);
    return TRUE;
}

int LengthAQueue(const AQueue *Q)
{
    return (Q->rear-Q->front+Q->length)%Q->length;
}


Status EnAQueue(AQueue *Q, void *data)
{
	if (IsFullAQueue(Q))
	{
		printf("队列满了！不能再入队了！\n");
		return FALSE;
	}
	if (IsEmptyAQueue(Q))
	{
		memcpy(Q->data[Q->front], data, 20);
		Q->rear = (Q->rear + 1) % Q->length;
		count = Q->rear;
		return TRUE;
	}
    memcpy(Q->data[Q->rear], data, 20);
	Q->rear = (Q->rear + 1) % Q->length;
	count = Q->rear;
    return TRUE;
}




Status DeAQueue(AQueue *Q)
{
	if (IsEmptyAQueue(Q))
	{
		printf("队列是空的！出不了队！\n");
		return FALSE;
	}
    Q->front = (Q->front+1)%Q->length;
    return TRUE;
}



void ClearAQueue(AQueue *Q)
{
	if (IsEmptyAQueue(Q))
	{
		printf("队列已经是空的了！\n");
		return;
	}
    Q->front = Q->rear = 0;
    count = Q->rear;
    printf("清空队列成功！\n");
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q, char typeData))
{
    if(Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
	if (IsEmptyAQueue(Q))
	{
		printf("队列里面什么都没有!\n");
		return FALSE;
	}
	int i = 0;
	while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE) {
		foo(Q->data[Q->front+i], dataType[Q->front+i]);
		i = (i + 1) % MAXQUEUE;
	}
    return TRUE;
}

//根据类型遍历
void APrint(void *q, char type) {
//	printf("\n函数里%c\n",type);// 输出
//	printf("2222222\n");

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


