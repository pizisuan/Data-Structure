/*线性表单链表存储结构*/

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;
typedef struct Node *LinkList;   /*定义LinkList*/

/*单链表的读取*/
/*
获取链表第i个数据的算法思路：
1.声明一个结点p指向链表第一个结点，初始化j从1开始；
2.当j<i时，就遍历链表，让p的指针向后移动，不断指向下一个结点，j累加1；
3.若到链表末尾p为空，则说明第i个元素不存在；
4.否则查找成功，返回结点p的数据。
*/

/*初始条件：顺序线性表L已存在，1<=i<=ListLength(L)*/
/*操作结果：用e返回L中第i个数据元素的值*/

Status GetElem (LinkList L, int i, ElemType *e)
{
	int j
	LinkList p;        /*声明一结点p*/
	p = L->next;       /*让p指向链表L的第一个结点*/
	j = 1;             /*j为计数器*/
	while(p && j<i)
	{
		p = p->next;   /*让p指向下一个结点*/
		++j;
	}
	if(!p || j>i)
	{
		return ERROR;  /*第i个元素不存在*/
	}
	*e = p->data;      /*取第i个元素的数据*/
	return OK;
}

/*单链表的插入*/
/*
单链表第i个数据插入结点的算法思路：
1.声明一个结点p指向链表第一个结点，初始化j从1开始;
2.当j<i时，就遍历链表，让p的指针向后移动，不断指向下一个结点，j累加1;
3.若到链表末尾p为空，则说明第i个元素不存在;
4.否则查找成功，在系统中生成一个空结点s;
5.将数据元素e赋值给s->data;
6.单链表的插入标准语句 s->next = p->next; p->next = s;
7.返回成功
*/

/*初始条件：顺序线性表L已存在，1<=i<=ListLength(L)*/
/*操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1*/

Status ListInsert(LinkList *L, int i, ElemType e)
{
	int j;
	LinkList p,s;
	p = *L;
	j = 1;
	while(p && j < i)
	{
		p = p->next;
		++j;
	}
	if(!p || j > i)
		return ERROR;                     /*第i个元素不存在*/
	s = (LinkList)malloc(sizeof(Node));   //生成新结点
	s->data = e;
	s->next = p->next;                    //将p的后续结点赋值给s的后继
	p->next = s;                          //将s赋值给p的后继
	return OK;
}

/*单链表的删除*/
/*
单链表第i个数据删除结点的算法思路：
1.声明一个结点p指向链表第一个结点，初始化j从1开始;
2.当j<i时，就遍历链表，让p的指针向后移动，不断指向下一个结点，j累加1;
3.若到链表末尾p为空，则说明第i个元素不存在;
4.否则查找成功，将欲删除的结点p->next赋值给q;
5.单链表的删除标准语句 p->next = q->next;
6.将q结点中的数据赋值给e，作为返回;
7.释放q结点;
8.返回成功
*/

/*初始条件：顺序线性表L已存在，1<=i<=ListLength(L)*/
/*操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1*/

Status ListInsert(LinkList *L, int i, ElemType *e)
{
	int j;
	LinkList p,q;
	p = *L;
	j = 1;
	while(p->next && j < i)    //遍历寻找第i个元素
	{
		p = p->next;
		++j;
	}
	if(!(p->next) || j > i)
		return ERROR;    /*第i个元素不存在*/
	q = p->next;
	p->next = q->next;   //将q的后继赋值给p的后继
	*e = q->data;        //将q结点的数据赋值给e
	free(q);             //让系统回收此结点，释放内存
	return OK;
}

/*单链表的创建*/
/*
单链表整表创建的算法思路：
1.声明一个结点p和计数器变量i;
2.初始化一空链表L;
3.让L的头结点的指针指向NULL，则建立一个带头结点的单链表;
4.循环：
  a.生成一新结点赋值给p;
  b.随机生成一数字赋值给p的数据域p->data;
  c.将p插入到头结点与前一新结点之间;
*/

//随机产生n个元素的值，建立带表头结点的单链表L（头插法）
void CreateListHead(LinkList *L, int n)
{
	LinkList p;
	int i;
	srand(time(0));                             //初始化随机种子
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;                          //先建立一个带头结点的单链表
	for(i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));     //生成新结点
		p->data = rand()%100+1                  //随机生成100以内的数字
		p->next = (*L)->next;
		(*L)->next = p;                         //插入到表头
	}
}

//随机产生n个元素的值，建立带表头结点的单链表L（尾插法）
void CreateListTail(LinkList *L, int n)
{
	LinkList p,r;
	int i;
	srand(time(0));                              //初始化随机种子
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;                                      //*r为指向尾部的结点
	(*L)->next = NULL;                           //先建立一个带头结点的单链表
	for(i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));      //生成新结点
		p->data = rand()%100+1                   //随机生成100以内的数字
		r->next = p;                             //将表尾终端结点的指针指向新结点
		r = p;                                   //将当前新结点定义为表尾终端结点
	}
	r->next = NULL;                              //表示当前链表结束
}

/*单链表的整表删除*/
/*
单链表整表删除的算法思路：
1.声明一个结点p和q;
2.将第一个结点赋值给p;
3.让L的头结点的指针指向NULL，则建立一个带头结点的单链表;
4.循环：
  a.将下一结点赋值给q;
  b.释放p;
  c.将q赋值给p;
*/

/*初始条件：顺序线性表已存在，操作结果：将L重置为空表*/
Status ClearList(LinkList *L)
{
	LinkList p,q;
	p = (*L)->next;        //p指向第一个结点
	while(p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*p)->next = NULL;     //头结点指针域为空
	return OK;
}
