//顺序存储的结构定义
#define MAXSIZE 20    /*存储空间初始分配量*/
typedef int ElemType;   /* ElemType 类型根据实际情况而定，这里假设为int*/
typedef struct
{
	ElemType data[MAXSIZE];     /*数组存储数据元素，最大值为MAXSIZE*/
	int length;                 /*线性表当前长度*/
}SqLsit；


// 获取元素操作

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

/*Status 是函数的类型，其值是函数结果状态代码，如OK等*/
/*初始条件：顺序线性表L已存在，1<=i<=ListLength(L)*/
/*操作结果：用e返回L中第i个数据元素的值*/

Status GetElem (sqList L , int i, ElemType *e)
{
	if(L.length == 0 || i < 1 || i > L.length)
		return ERROR;
	*e = L.data[i-1];
	return OK;
}


// 插入操作
/*
  插入算法的思路：
	1.如果插入位置不合理，抛出异常；
	2.如果线性表长度大于数组长度，则抛出异常或动态增加容量；
	3.从最后一个元素开始向前遍历到第i个位置，分别将它们都向后移动一个位置；
	4.将要插入的元素填入位置i处；
	5.表长加1
	
*/

/*初始条件：顺序线性表L已存在，1<=i<=ListLength(L)*/
/*操作结果：在L中第i个位置之前插入新的数据元素e,L的长度加1*/

Status ListInsert(SqLsit *L, int i, ElemType e)
{
	int k;
	if(L->length==MAXSIZE)  /*顺序线性表已经满*/
		return ERROR;
	if(i < 1 || i > L->length +1) /*当i不在范围内时*/
		return ERROR;
	if(i <= L->length)   /*若插入数据位置不在表尾*/
	{
		for(k = L->length-1 , k >= i-1, k--)
		{
			L->data[k+1] = L->data[k];
		}
	}
	L->data[i-1] = e;   /*将新元素插入*/
	L->length++;
	return OK;
}


//删除操作
/*
  删除算法的思路：
	1.如果删除位置不合理，抛出异常；
	2.取出删除元素
	3.从删除元素开始遍历到最后一个元素位置，分别将它们都向前移动一个位置；
	4.表长减一
*/

/*初始条件：顺序线性表L已存在，1<=i<=ListLength(L)*/
/*操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1*/

Status ListInsert(SqLsit *L, int i, ElemType *e)
{
	int k;
	if(L->length==0)  /*线性表为空*/
		return ERROR;
	if(i < 1 || i > L->length) /*删除位置不正确*/
		return ERROR;
	*e = L->data[i-1];
	if(i < L->length)   /*如果删除的不是最后位置*/
	{
		for(k = i , k < L->length, k++)
		{
			L->data[k-1] = L->data[k];          //将删除位置后继元素前移
		}
	}
	L->length--;
	return OK;
}
