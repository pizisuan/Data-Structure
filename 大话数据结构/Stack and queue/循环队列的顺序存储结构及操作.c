
//循环队列顺序存储结构
typedef int QElemType   //QElemType类型根据实际情况而定，这里假设为int

typedef struct
{
	QElemType data[MAXSIZE];
	int front;  //头指针
	int rear;   //尾指针，若队列不为空，指向队列尾元素的下一个位置
}SqQueue;

/*循环队列的初始化*/
//初始化一个空队列Q
Status InitQueue(SqQueue* Q)
{
	Q->front = 0;
	Q->rear = 0;
	return ok;
}

/*循环队列求队列长度*/
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE)% MAXSIZE;
}

/*循环队列的入队列操作*/
/*若队列未满，则插入元素e为Q新的队列元素*/
Status EnQueue(SqQueue* Q,QElemType e)
{
	if((Q->rear + 1)%MAXSIZE == Q->front)  //队列满的判断
	{
		return ERROR;
	}
	Q->data[rear] = e;   //将元素e赋值给队尾
	Q->rear = (Q->rear + 1)%MAXSIZE;   //rear指针向后移一位，若到最后则移到数组头部
	return OK;
}

/*循环队列的出队列操作*/
/*若队列不空，则删除Q中队头元素，用e返回其值*/
Status DeQueue(SqQueue* Q,QElemType* e)
{
	if(Q->front == Q->rear)   //队列空的判断
	{
		return ERROR;
	}
	*e = Q->data[Q->front];   //将队头元素赋值给e
	Q->front = (Q->front + 1)%MAXSIZE;   //将front指针向后移动一位，若到最后则移到数组头部
	return OK;
}
