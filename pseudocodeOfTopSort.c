#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
void TopSort(GraphList g)
{
	Queue q;
	int Counter = 0;
	VertexNode V, W;

	Q = CreateQueue(MAXVEX);
	MakeEmpty(Q);
	for each vertex V
		if (Indegree[V] == 0)
			Enqueue(V,Q);

	while (!Empty(Q))
	{
		V = DeQueue(Q);
		TopNum[V] = Counter++;// flag means this node is been visited

		for each W adjacent to V
			if (--Indegree[W] == 0)
				Enqueue(W,Q);
	}

	if (Counter != MAXVEX)
		printf("Graph has a cycle");

	DisposeQueue(Q);
}
