#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "Queue.h"

void TopSort(GraphList g)
{
	Queue Q;
	int Counter = 0;
	int V, W;
	int indegree[MAXVEX];	//维护每个节点的入度(indegree)，初始化时需要遍历整张图
	int topNum[MAXVEX];
	EdgeNode* p;


	Q = CreateQueue(MAXVEX);
	MakeEmpty(Q);
	for (int i = 0; i < g.numVertexes; i++)
	{
		if (indegree[i] == 0)
			Enqueue(i, Q);
	}

	while (!IsEmpty(Q))
	{
		V = Dequeue(Q);	//队列的操作需要重写
		topNum[V] = Counter++;

		for (int i = 0; i < MAXVEX; i++)
		{
			p = g.adjList[i].firstedge;

			//此处代码可用初始化indegree数组,表示入度

			//while (p != NULL)
			//{
			//	if (p->adjvex == V)
			//		indegree[V]++;
			//}

			while (p != NULL)
			{
				if (--indegree[W])
					Enqueue(W,Q);
			}
		
		}
	}

	if (Counter != MAXVEX)
		printf("Graph has a circule\n");

	DisposeQueue(Q);

}
