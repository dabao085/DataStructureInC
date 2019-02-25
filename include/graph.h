/*
 * Author: Cheng xiang
 * Date: 2019-2-25
 * header of graph structure
*/

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "datastructureinc.h"

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


int Locate(GraphList* g, char ch);

void CreateGraph(GraphList *g);

void printGraph(GraphList *g);

#endif

