/*二叉排序树的查找*/

/*二叉树的二叉链表结点结构定义*/
typedef struct BiTNode              /*结点结构*/
{
	int data;                       /*结点数据*/
	struct BiTNode *lchild, *rchild     /*左右孩子指针*/
}BiTNode, *BiTree;


/*
   递归查找二叉排序树T中是否存在key
   指针f指向T的双亲，其初始调用值为NULL
   若查找成功，则指针p指向该数据元素结点，并返回TRUE
   否则指针p指向查找路径上访问的最后一个结点并返回FALSE
*/

Status SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
	if (!T)        /*查找不成功*/
	{
		*p = f;
		return FALSE;
	}
	else if (key == T->data)        /*查找成功*/
	{
		*p = T;
		return TRUE;
	}
	else if (key < T->data)
	{
		return SearchBST(T->lchild, key, T, p);        /*在左子树继续查找*/
	}
	else
	{
		return SearchBST(T->rchild, key, T, p);       /*在右子树继续查找*/
	}
}


/*二叉排序树的插入*/

/*
  当二叉排序树T中不存在关键字等于key的数据元素时，插入key并返回TRUE，否则返回FALSE
*/

Status InsertBST(BiTree *T, int key)
{
	BiTree p,s;
	if (!SearchBST(*T，key, NULL, &p))   /*查找不成功*/
	{
		s = (BiTree) malloc(sizeof(BiTNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p)
		{
			*T = s;      /*输入s为新的根结点*/
		}
		else if (key < p->data)
		{
			p->lchild = s;      /*插入s为左孩子*/
		}
		else
		{
			p->rchild = s;      /*插入s为右孩子*/
		}
		return TRUE;
	}
	else
	{
		return FALSE;         /*树中已有关键字相同的结点，不在插入*/
	}
}

****************************************************************************************
/*
  基于上面两点，可以实现二叉排序树的构建
*/

int i;
int a[10] = {62,88,58,47,35,73,51,99,37,93}
BiTree T = NULL;
for ( i = 0; i < 10; ++i)
{
	InsertBST(&T, a[i]);
}

****************************************************************************************

/*二叉排序树的结点删除*/

Status DeleteBST(BiTree *T, int key)
{
	if (!*T)      /*不存在关键字等于key的数据元素*/
	{
		return FALSE;
	}
	else
	{
		if (key == (*T)->data)     /*找到关键字等于key的数据元素*/
		{
			return Delete(T);
		}
		else if (key < (*T)->data)
		{
			return DeleteBST(&(*T) ->lchild, key);
		}
		else
		{
			return DeleteBST(& (*T) ->rchild, key);
		}
	}
}

/*从二叉排序树中删除结点p,并重新它的左获右子树*/

Status Delete(BiTree *p)
{
	BiTree q,s;
	if ((*p) -> rchild == NULL)    /*右子树空则只需要重接它的左子树*/
	{
		q = *p; *p = (*p) -> lchild; free(q);
	}
	else if ((*p) -> lchild == NULL)    /*只需重接它的右子树*/
	{
		q = *p; *p = (*p) -> rchild; free(q);
	}
	else   /*左右子树均不变*/
	{
		q = *p; s = (*p) -> lchild;
		while(s->rchild)  /*转左，然后向右到尽头（找待删结点的前驱）*/
		{
			q = s; s = s-> rchild;
		}
		(*p) -> data = s -> data;    /* s指向被删除结点的直接前驱*/
		if (q!=*p)
		{
			q -> rchild = s -> lchild;  /*重接q的右子树*/
		}
		else
		{
			q -> lchild = s -> lchild;  /*重接q的左子树*/
		}
		free(s)
	}

	return TRUE;
}
