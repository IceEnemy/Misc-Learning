#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int parentList[255] = {};

struct Edge{
	int source;
	int destination;
};

struct Graph{
	int verticesCount;
	int edgesCount;
	Edge *edges;
};

struct Graph *createGraph(int verticesCount, int edgesCount){
	struct Graph *newGraph = (struct Graph *)malloc(sizeof(struct Graph));
	newGraph->verticesCount = verticesCount;
	newGraph->edgesCount = edgesCount;
	newGraph->edges = (struct Edge*)malloc(sizeof(struct Edge) * edgesCount);
	
	return newGraph;
}

void makeSet(int vCount){
	for(int i=0; i<vCount; i++){
		parentList[i] = i;
	}
}

int findParent(int vertex){
	if(parentList[vertex] == vertex){
		return vertex;
	}
//	return findParent(parentList[vertex]);
	
	parentList[vertex] = findParent(parentList[vertex]);
	return parentList[vertex];
}

void join(int vertexA, int vertexB){
	int parentA = findParent(vertexA);
	int parentB = findParent(vertexB);
	parentList[parentA] = parentB;
}

bool isSameSet(int vertexA, int vertexB){
	return (findParent(vertexA) == findParent(vertexB))? true:false;
}

bool Union(struct Graph *graph){
	for(int i=0; i<graph->edgesCount; i++){
		int sourceParent = findParent(graph->edges[i].source);
		int destinationParent = findParent(graph->edges[i].destination);
		
		if(sourceParent == destinationParent){
			return true;
		}
		
		parentList[sourceParent] = destinationParent;
	}
	return false;
}

bool isCyclic(struct Graph *graph){
	makeSet(graph->verticesCount);
	return Union(graph);
}

int main()
{
	makeSet(5);
	join(0,1);
	join(1,2);
	join(2,3);
	join(3,4);
	
	if(isSameSet(0,4)) printf("True\n");
	else printf("False\n");
	
	struct Graph *graph = createGraph(6,5);
	graph->edges[0].source = 0;
	graph->edges[0].destination = 1;
	
	graph->edges[1].source = 0;
	graph->edges[1].destination = 2;
	
	graph->edges[2].source = 1;
	graph->edges[2].destination = 3;
	
	graph->edges[3].source = 3;
	graph->edges[3].destination = 4;
	
	graph->edges[4].source = 2;
	graph->edges[4].destination = 4;
	
	if(isCyclic(graph)) printf("it is cyclic\n");
	else printf("it isn't cyclic\n");
	
 	return 0;
}

