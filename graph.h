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



void CreateGraph(GraphList *g)
{
	int i,j,k;
	EdgeNode *e;
	EdgeNode *f;
	printf("Enter the number of vertex and edges:\n");
	scanf("%d,%d",&g->numVertexes,&g->numEdges);

	for(i = 0; i < g->numVertexes; i++)
	{
		printf("please enter vertex %d:\n",i);
		g->adjList[i].data = getchar();
		g->adjList[i].firstedge = NULL;
		while(g->adjList[i].data == '\n')
		{
			g->adjList[i].data = getchar();
		}
	}
	for(k = 0;k<g->numEdges; k++)
	{
		printf("input edge<vi,vj>:\n");
		char p,q;
		p = getchar();
		while(p == '\n')
		{
			p = getchar();
		}
		q = getchar();
		while(q == '\n')
		{
			q = getchar();
		}
		int m,n;
		m = Locate(g,p);
		n = Locate(g,q);
		if(m == -1|| n == -1)
		{
			return ;
		}

		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		if(e == NULL)
		{
			printf("malloc failed!\n");
			return ;
		}
		e->adjvex = n;
		e->next = g->adjList[i].firstedge;
		g->adjList[m].firstedge = e;



	}
}
