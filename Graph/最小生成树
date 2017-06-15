/*最小生成树*/

/*Prim算法*/
void MiniSpanTree_Prim(MGraph G)
{

	int min,i,j,k;
	int adjvex[MAXVEX];     /*保存相关顶点下标*/
	int lowcost[MAXVEX];    /*保存相关顶点间边的权值*/
	lowcost[0] = 0;         /*初始化第一个权值为0，即V0加入生成树*/
                            /*lowcost的值为0，在这里就是此下标的顶点已经加入生成树*/
	adjvex[0] = 0;          /*初始化第一个顶点下标为0*/

	for (int i = 0; i < G.numVertexes; ++i)   /*循环除下标为0外的全部顶点*/
	{
		lowcost[i] = G.arc[0][i];    /*将v0顶点与之有边的权值存入数组*/
		adjvex[i] = 0;               /*初始化都为v0的下标*/
	}

	for (int i = 0; i < G.numVertexes; ++i)
	{
		min = INFINITY;  /*初始化最小权值为无穷大，通常设置为不可能的大数字如65535*/
		j = 1;
		k = 0;
		while(j < G.numVertexes)
		{
			if (lowcost[j]!=0 && lowcost[j] < min)
			{
				/* 如果权值不为0且权值小于min */
				min = lowcost[j];     /*则让当前权值成为最小值*/
				k = j;                /*将当前最小值的下标存入k*/
			}
			k++;
		}

		printf("(%d,%d)",adjvex[k],k);    /*打印当前顶点边中权值最小边*/
		lowcost[k] = 0;      /*将当前顶点的权值设置为0，表示此顶点已经完成任务*/

		for (int j = 1; j < G.numVertexes; ++j)
		{
			if (lowcost[j]!=0 && G.arc[k][j] < lowcost[j])
			{
				/* 若下标为k顶点的各边权值小于此前这些顶点未被加入生成树的权值 */
				lowcost[j] = G.arc[k][j];    /*将较小权值存入lowcost*/
				adjvex[j] = k;               /*将下标为k的顶点存入adjvex*/
			}
		}
	}
}
****************************************************************************************************************************
/*Kruskal算法*/

void MiniSpanTree_Kruskal(MGraph G)  /*生成最小生成树*/
{
	int i,n,m;
	Edge deges[MAXEDGE];   /*定义边集数组*/
	int parent[MAXVEX];    /*定义一数组用来判断边与边是否形成环路*/

	/*此处省略邻接矩阵G转化为边集数组edges并按权由小到大排序的代码*/
	for (int i = 0; i < G.numVertexes; ++i)
	{
		parent[i] = 0;    /*初始化数组值为0*/
	}

	for (int i = 0; i < G.numEdges; ++i)   /*循环每一条边*/
	{
		n = Find(parent,edges[i].begin);
		m = Find(parent,edges[i].end);
		if (n != m)   //假如n与m不等，说明此边没有与现有生成树形成环路
		{
			parent[n] = m;   /*将此边的结尾顶点放入下标为起点的parent中*/
			printf("(%d,%d) %d",edges[i].begin,edges[i].end,edges[i].weight );
		}
	}
}

int Find(int * parent, int f)   /*查找连线顶点的尾部下标*/
{
	while(parent[f]>0)
	{
		f = parent[f];
	}
	return f;
}
