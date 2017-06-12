/*图的邻接矩阵存储结构*/

typedef char VertexType;  // 顶点类型应由用户定义
typedef int EdgeType;     //边上的权值类型应由用户定义
#define MAXVEX 100        //最大顶点数，应由用户定义
#define INFINITY 65535    //用65535来表示无穷大

typedef struct MGraph
{
	VertexType vexs[MAXVEX];         //顶点表
	EdgeType arc[MAXVEX][MAXVEX];    //邻接矩阵，可看作表
	int numVertexes, numEdges;       //图中当前的顶点数和边数
};

//建立无向网图的邻接矩阵表示
void CreateMGraph(MGraph* G)
{
	int i,j,k,w;
	printf("输入顶点数和边数：\n");
	scanf("%d,%d",&G->numVertexes,&G->numEdges); //输入顶点和边数
	for (int i = 0; i < G->numVertexes; ++i)  //读入顶点信息，建立顶点表
	{
		scanf(&G->vexs[i]);
	}
	for (int i = 0; i < G->numVertexes; ++i)
	{
		for (int j = 0; j < G->numVertexes; ++j)
		{
			G->arc[i][j] = INFINITY;   //邻接矩阵初始化
		}
	}
	for (int i = 0; i < G->numEdges; ++i) //读入numEdges条边，建立邻接矩阵
	{
		printf("输入边（vi,vj）上的下标i,下标j和权w\n");
		scanf("%d,%d,%d",&i,&j,&w);  //输入边(vi,vj)上的权w
		G->arc[i][j] = w;
		G->arc[i][j] = G->arc[i][j];  //因为是无向图，矩阵对称
	}
}

/*图的邻接表存储结构*/
typedef char VertexType;    /*顶点类型应由用户定义*/
typedef int EdgeType;       /*边上的权值类型应由用户定义*/

typedef struct EdgeNode     /*边表结点*/
{
	int adjvex;             /*邻接点域，存储该顶点对应的下标*/
	EdgeType weight;        /*用于存储权值，对于非网图可以不需要*/
	struct EdgeNode* next;  /*键域，指向下一个邻接点*/
}EdgeNode;

typedef struct VertexNode   /*顶点表结点*/
{
	VertexType data;        /*顶点域，存储顶点信息*/
	EdgeNode* firstdege;    /*表边头指针*/
}VertexNode, AdjList[MAXVEX];

typedef struct 
{
	AdjList adjList;
	int numVertexes,numEdges;    /*图中当前顶点数和边数*/
}GraphAdjList;

/*无向图的邻接表创建*/
/*建立图的邻接表结构*/

void CreateALGraph(GraphAdjList* G)
{
	int i,j,k;
	EdgeNode* e;
	printf("输入顶点数和边数：\n" );
	scanf("%d,%d",&G->numVertexes,&G->numEdges);  /*输入顶点和边数*/
	for (int i = 0; i < G->numVertexes; ++i)   /*读入顶点信息，建立顶点表*/
	{
		scanf(&G->adjList[i].data);   /*输入顶点信息*/
		G->adjList[i].firstdege = NULL;   /*将边表设置为空表*/
	}
}

for (int k = 0; k < G->numEdges; ++k)
{
	printf("输入边(vi,vj)上的顶点序号：\n");
	scanf("%d,%d",&i,&j);   /*输入边(vi,vj)上的顶点序号*/
	e = (EdgeNode*) malloc (sizeof(EdgeNode));  //申请空间，生成结点
	e->adjvex = j   /*邻接序号为j*/
	e->next = G->adjList[i].firstdege; //将e指针指向当前顶点指向的结点
	G->adjList[i].firstdege = e;  /*将当前顶点的指针指向e*/

	e = (EdgeNode*) malloc (sizeof(EdgeNode));  //申请空间，生成结点
	e->adjvex = i   /*邻接序号为i*/
	e->next = G->adjList[j].firstdege; //将e指针指向当前顶点指向的结点
	G->adjList[j].firstdege = e;  /*将当前顶点的指针指向e*/
}
