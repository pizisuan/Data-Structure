//队列的链式存储结构及操作

//链队列的结构
typedef int QElemType  //QElemType类型根据实际情况而定，这里假设为int
typedef struct QNode  //结点结构
{
	QElemType data;
	struct QNode* Next;
}QNode, *QueuePtr;

typedef struct     //队列的链表结构
{
	QueuePtr front,rear;   //队头，队尾指针
}LinkQueue;


//入队操作
/*插入元素e为Q的新的队列元素*/
Status EnQueue(LinkQueue* Q, QElemType e)
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if(!s)
	{
		exit(OVERFLOW);
	}
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;  //把拥有元素e的新结点s赋值给原队尾结点的后继
	Q->rear = s;    //把当前s设置为队尾结点，rear指向s
	return OK;
}

//出队操作
/*若队列不空，删除Q的队头元素，用e返回其值，并返回OK，否则返回ERROR*/
Status DeQueue(LinkQueue* Q, QElemType *e)
{
	QueuePtr p;
	if(Q->front == Q->rear)
	{
		return ERROR;
	}
	p = Q->front->next   //将欲删除的对头结点暂时存储给p
	*e = p->data;  //将欲删除的队头结点赋值给e
	Q->front->next = p->next;   //将原队头结点的后继赋值给头结点后继
	if(p->front == p)   //若队头是队尾，则删除后将rear指向头结点
	{
		Q->rear = Q->front;
	}
	free(p);
	return OK;
}
