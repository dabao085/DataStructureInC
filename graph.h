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
