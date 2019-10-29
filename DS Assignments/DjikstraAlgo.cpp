// A C++ program for Dijkstra's single source shortest path algorithm. 
// The program is for adjacency matrix representation of the graph 

#include <stdio.h> 
#include <limits.h> 

#define V 4  // For Current Testing Scenario I have fixed Vertice = 9

int minDistance(int dist[], bool sptSet[]) 
{ 
int min = INT_MAX, min_index; 

for (int v = 0; v < V; v++) 
	if (sptSet[v] == false && dist[v] <= min) 
		min = dist[v], min_index = v; 

return min_index; 
} 

int printSolution(int dist[], int n) 
{ 
printf("Vertex  -  Distance from Source\n"); 
for (int i = 0; i < V; i++) 
	printf("  %d \t\t  %d\n", i, dist[i]); 
} 


void dijkstra(int graph[V][V], int src) 
{ 
	int dist[V];	  

	bool sptSet[V];  


	for (int i = 0; i < V; i++) 
		dist[i] = INT_MAX, sptSet[i] = false; 


	dist[src] = 0; 


	for (int count = 0; count < V-1; count++) 
	{ 
 
	int u = minDistance(dist, sptSet); 


	sptSet[u] = true; 

	for (int v = 0; v < V; v++) 
		if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
									&& dist[u]+graph[u][v] < dist[v]) 
			dist[v] = dist[u] + graph[u][v]; 
	} 

	printSolution(dist, V); 
} 

int main() 
{ 
	int graph[V][V] = {{0, 10, 20, 0}, 
						{10, 0, 5, 6}, 
						{20, 5, 0, 20}, 
						{0, 6, 20, 0}}; 

	dijkstra(graph, 0); 

	return 0; 
} 
