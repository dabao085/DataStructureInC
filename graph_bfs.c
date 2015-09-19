#include "graph.h"

void BFS(GraphList g)
{
	int i;
	int visited[MAXVEX];
	EdgeNode *p;
	Queue q;
	for (i = 0; i < g.numVertexes; i++)
	{
		visited[i] = 0;
	}

	InitQueue(&q);
	for (i = 0; i < g.numVertexes; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			printf("%c ",g.adjList[i].data);
			EnQueue(&q,i);
			while (!QueueEmtpy(q))
			{
				int m;
				DeQueue(&q,&m);
				p = g.adjList[i].firstedge;
				while (p)
				{
					if (!visited[p->adjvex])
					{
						visited[p->adjvex] = 1;
						printf("%c ",g.adjList[p->adjvex].data);
						EnQueue(&q,p->adjvex);
					}
					p = p->next;
				}
			}
		}
	}
}
