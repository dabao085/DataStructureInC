#ifndef _GRAPH_H
#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 1000

typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode
{
	int adjvex;
	EdgeType weight;
	struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode
{
	VertexType data;
	EdgeNode * firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct Graph
{
	AdjList adjList;
	int numVertexes, numEdges;
}GraphList;


int Locate(GraphList* g, char ch)
{
	int i;
	for (i = 0; i < MAXVEX; i++)
	{
		if (ch == g->adjList[i].data)
		{
			break;
		}
	}
	if (i >= MAXVEX)
	{
		printf("can't find this vertex\n");
		return -1;
	}
	return i;
}
void CreateGraph(GraphList *g)
{
	int i, j, k;
	EdgeNode *e;
	EdgeNode *f;
	printf("Enter the number of vertex and edges:\n");
	scanf("%d,%d", &g->numVertexes, &g->numEdges);

	for (i = 0; i < g->numVertexes; i++)
	{
		printf("please enter vertex %d:\n", i);
		g->adjList[i].data = getchar();
		g->adjList[i].firstedge = NULL;
		while (g->adjList[i].data == '\n')
		{
			g->adjList[i].data = getchar();
		}
	}
	for (k = 0; k<g->numEdges; k++)
	{
		printf("input edge<vi,vj>:\n");
		char p, q;
		p = getchar();
		while (p == '\n')
		{
			p = getchar();
		}
		q = getchar();
		while (q == '\n')
		{
			q = getchar();
		}
		int m, n;
		m = Locate(g, p);
		n = Locate(g, q);
		if (m == -1 || n == -1)
		{
			return;
		}

		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		if (e == NULL)
		{
			printf("malloc failed!\n");
			return;
		}
		e->adjvex = n;
		e->next = g->adjList[i].firstedge;
		g->adjList[m].firstedge = e;

		f = (EdgeNode *)malloc(sizeof(EdgeNode));
		f->next = g->adjList[i].firstedge;
		g->adjList[n].firstedge = f;

	}
}

void printGraph(GraphList *g)
{
	int i = 0;
	while (g->adjList[i].firstedge != NULL &&i<MAXVEX)
	{
		printf("Vertex:%c ",g->adjList[i].data);
		EdgeNode* e = NULL;
		e = g->adjList[i].firstedge;
		while (e != NULL)
		{
			printf("%d ",e->adjvex);
			e = e->next;
		}
		i++;
		printf("\n");
	}
}

#endif

