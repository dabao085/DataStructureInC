#include "graph.h"

int visited[MAXVEX];

void DFS(GraphList g, int i)
{
	EdgeNode *p;
	visited[i] = 1;
	printf("%c ",g.adjList[i].data);
	p = g.adjList[i].firstedge;
	while (p)
	{
		if (!visited[p->adjvex])
		{
			DFS(g, p->adjvex);
		}
		p = p->next;
	}
}

void DFSTraverse(GraphList g)
{
	int i;
	for (i = 0; i < g.numVertexes; i++)
	{
		visited[i] = 0;
	}
	for (i = 0; i < g.numVertexes; i++)
	{
		if (!visited[i])
		{
			DFS(g,i);
		}
	}
}
