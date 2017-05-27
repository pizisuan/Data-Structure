/*树的存储结构*/

/*
   这里介绍三种表示方法：双亲表示法、孩子表示法、孩子兄弟表示法
*/

/*树的双亲表示法结构定义*/
#define MAX_TREE_SIZE 100
typedef int TElemType  /*树结点的数据类型，目前暂定位整型*/
typedef struct PTNode /*结点结构*/
{
	TElemType data;    /*结点数据*/
	int parent;  /*双亲位置*/
}PTNode;

typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];   /*结点数组*/
	int r,n;    /*根的位置和结点数*/
}PTree;

/*树的孩子表示法结构定义*/
#define MAX_TREE_SIZE 100
typedef struct CTNode  /*孩子结点*/
{
	int child;
	struct CTNode* next;
}*ChildPtr;

typedef struct /*表头结构*/
{
	TElemType data;
	ChildPtr firstchild;
}CTBox;

typedef struct  /*树结构*/
{
	CTBox nodes[MAX_TREE_SIZE]; /*结点数组*/
	int r,n;  /*根的位置及结点数*/
}CTree;

/*树的孩子兄弟表示法结构定义*/
/*其最大的优势在于：将一颗复杂的树变成二叉树*/
typedef struct CSNode
{
	TElemType data;
	struct CSNode* firstchild,*rightsib;
}CSNode,*CSTree;
