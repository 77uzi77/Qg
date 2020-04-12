#include "../AQueue/AQueue.h"
extern int count;

void InitAQueue(AQueue *Q)
{
    int i;
	Q->length = MAXQUEUE;
    for(i = 0; i < MAXQUEUE; i++)
        //��֪���û��������������ʹ�С�����Ը���20
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
		printf("����Ϊ�գ�û�ж�ͷ��\n");
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
		printf("�������ˣ�����������ˣ�\n");
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
		printf("�����ǿյģ������˶ӣ�\n");
		return FALSE;
	}
    Q->front = (Q->front+1)%Q->length;
    return TRUE;
}



void ClearAQueue(AQueue *Q)
{
	if (IsEmptyAQueue(Q))
	{
		printf("�����Ѿ��ǿյ��ˣ�\n");
		return;
	}
    Q->front = Q->rear = 0;
    count = Q->rear;
    printf("��ն��гɹ���\n");
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q, char typeData))
{
    if(Q->data[0] == NULL)
    {
        printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
        return FALSE;
    }
	if (IsEmptyAQueue(Q))
	{
		printf("��������ʲô��û��!\n");
		return FALSE;
	}
	int i = 0;
	while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE) {
		foo(Q->data[Q->front+i], dataType[Q->front+i]);
		i = (i + 1) % MAXQUEUE;
	}
    return TRUE;
}

//�������ͱ���
void APrint(void *q, char type) {
//	printf("\n������%c\n",type);// ���
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


