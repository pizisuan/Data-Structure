/*图的遍历*/

/*深度优先遍历*/
typedef int Boolean;     /*Boolean 是布尔类型，其值是TRUE或FALSE*/
Boolean visited[MAX];    /*访问标志的数组*/

/*邻接矩阵的深度优先递归算法*/
void DFS(MGraph G, int i)
{
	int j;
	visited[i]  =TRUE;
	printf("%c\n",G.vexs[i] );   /*打印顶点，也可以其他操作*/
	for (int j = 0; j < G.numVertexes; ++i)
	{
		if (G.arc[i][j] == 1 && !visited[j])
		{
			DFS(G,j);      /*对为访问的邻接顶点递归调用*/
		}
	}
}

/*邻接矩阵的深度遍历操作*/
void DFSTraverse(MGraph G)
{
	int i;
	for (int i = 0; i < G.numVertexes; ++i)
	{
		visited[i] = FALSE;     /*初始所有顶点状态都是未访问过状态*/
	}
	for (int i = 0; i < G.numVertexes; ++i)
	{
		if (!visited[i])
		{
			DFS(G,i);
		}
	}
}

**************************************************************************

/*邻接表的深度优先递归算法*/
void DFS(GraphAdjList GL, int i)
{
	EdgeNode* p;
	visited[i] = TRUE;
	printf("%c\n",GL->adjList[i].data );    /*打印顶点，也可以其他操作*/
	p = GL->adjList[i].firstedge;
	while(p)
	{
		if (!visited[p->adjvex])
		{
			DFS(GL,P->adjvex);     /*对为访问的邻接顶点递归调用*/
		}
		p = p->next;
	}
}

/*邻接表的深度遍历操作*/
void DFSTraverse(GraphAdjList GL)
{
	int i;
	for (int i = 0; i < GL->numVertexes; ++i)
	{
		visited[i] = FALSE;    /*初始所有顶点状态都是未访问过状态*/
	}
	for (int i = 0; i < GL->numVertexes; ++i)
	{
		if (!visited[i])  /*对未访问过的顶点调用DFS，若是连通图，只会执行一次*/
		{
			DFS(GL,i);
		}
	}
}

*******************************************************************
/*邻接矩阵的广度遍历算法*/

void BFSTraverse(MGraph G)
{
	int i,j;
	Queue Q;
	for (int i = 0; i < G.numVertexes; ++i)
	{
		visited[i] = FALSE;
	}
	InitQueue(&Q);    /*初始化一辅助用的队列*/
	for (int i = 0; i < G.numVertexes; ++i)    /*对每一个顶点作循环*/
	{
		if (!visited[i])
		{
			visited[i] = TRUE;          /*设置当前顶点访问过*/
			printf("%c\n",G.vexs[i]);   /*打印顶点，也可以其他操作*/
			EnQueue(&Q,i);              /*将此顶点入队列*/
			while(!QueueEmpty(Q))
			{
				DeQueue(&Q,&i);         /*将队中元素出队列，赋值给i*/
				for (int j = 0; j < G.numVertexes; ++j)
				{
					/* 判断其他顶点若与当前顶点存在边且未访问过 */
					if (G.arc[i][j] == 1 && !visited[j])
					{
						visited[j] = TRUE;     /*将找到的此顶点标记为已访问*/
						printf("%c\n",G.vexs[j]);  /*打印顶点*/
						EnQueue(&Q,j);     /*将找到的此顶点入队列*/
					}
				}
			}
		}
	}
}

/*邻接表的广度遍历算法*/
void BFSTraverse(GraphAdjList GL)
{
	int i;
	EdgeNode* P;
	Queue Q;
	for (int i = 0; i < GL->numVertexes; ++i)
	{
		visited[i] = FALSE;
	}
	InitQueue(&Q);
	for (int i = 0; i < GL->numVertexes; ++i)
	{
		if (!visited[i])
		{
			visited[i] = TRUE;
			printf("%c\n",GL->adjList[i].data);   /*打印顶点，也可以其他操作*/
			EnQueue(&Q,i);
			while(!QueueEmpty(Q))
			{
				DeQueue(&Q,&i);
				p = GL->adjList[i].firstedge;   /*找到当前顶点边表链表头指针*/
				while(p)
				{
					if (!visited[p->adjvex])   /*若此顶点未被访问*/
					{
						visited[p->adjvex] = TRUE;
						printf("%c\n",GL->adjList[p->adjvex].data);
						EnQueue(&Q,p->adjvex);   /*将此顶点入队列*/
					}
					p = p->next;     /*指针指向下一个邻接点*/
				}

			}
		}
	}
}
