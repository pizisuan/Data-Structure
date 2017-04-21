/*两栈共享空间结构*/
typedef struct
{
	SElemType data[MAXSIZE];
	int top1;   //栈1的栈顶指针
	int top2;   //栈2的栈顶指针
}SqDoubleStack;

/*插入元素e为新的栈顶元素*/

Status Push(SqDoubleStack* s, SElemType e, int stackNumber)
{
	if(s->top1 + 1 == s->top2)   //栈已满，不能再插入新元素
	{
		return ERROR;
	}
	if(stackNumber == 1)    //栈1有元素进栈
	{
		s->data[++s->top1] = e;   //若栈1则先top1+1后给数组元素赋值
	}
	else if(stackNumber == 2)
	{
		s->data[--s->top2] = e;   //若栈2则先top2-1后给数组元素赋值
	}
	return OK;
}

/*若栈不空，则删除s的栈顶元素，用e返回其值，并返回OK，否则返回ERROR*/

Status Pop(SqDoubleStack* s, SElemType* e, int stackNumber)
{
	if(stackNumber == 1)
	{
		if(s->top1 == -1)
	    {
		    return ERROR;       //说明栈1已经是空栈，溢出
	    }
		*e = s->data[s->top1--];    //将栈1的栈顶元素出栈
	}
	else if(stackNumber == 2)
	{
		if(s->top2 == MAXSIZE)
		{
			return ERROR;      //说明栈2已经是空栈，溢出
		}
		*e = s->data[s->top2++];  //将栈2的栈顶元素出栈
	}
	return OK;
}
