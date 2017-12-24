#include <iostream>
#include <utility>
#include <stack>

using namespace std;

void initializeGraph(int **graph, int vertices);
void createGraph(int **graph, int vertices);// Creates adjacency matrix for a graph	
void printGraph(int **graph, int vertices);	// Prints the graph in the form of adjacency matrix
bool isReachable(int **graph, int *visited, int vertices, int u, int v);// Return true if there is a path between u and v
bool isReachableIterative(int **graph, int vertices, int u, int v);	// Iterative method 

int main()
{

	int V;

	cout<<"Enter the number of vertices of the graph"<<endl;
	cin>>V;

	int **graph;
	int *visited;

	graph = new int *[V];
	visited = new int [V];

	for(int v=0; v<V; v++){
		graph[v] = new int[V];
	}

	createGraph(graph, V);
	printGraph(graph, V);

	int u,v;

	cout<<"Enter start and end positions to find if there is a route or not"<<endl;
	cin>>u>>v;

	visited[u] = 1;

	//bool result = isReachable(graph, visited, V, u, v);

	bool result = isReachableIterative(graph, V, u, v);

	if(result)
		cout<<"There is a path between "<<u<<" and "<<v<<endl;
	else
		cout<<"There is no path between "<<u<<" and "<<v<<endl;

}

void initializeGraph(int **graph, int vertices){
	for(int r=0; r<vertices; r++){
		for(int c=0; c<vertices; c++){
			graph[r][c] = 0;
		}
	}
}

void createGraph(int **graph, int vertices){
	initializeGraph(graph, vertices);
	int edges;

	cout<<"Enter the number of edges in the graph"<<endl;

	cin>>edges;

	cout<<"Enter edges in the graph in the form of u v , where edge is from u to v"<<endl;
	int edgeCount = 0;

	for(int edge = 0; edge < edges; edge++){
		int u,v; 
		cin>>u>>v;

		graph[u][v] = 1;
	}
}


void printGraph(int **graph, int vertices){
	int rows = vertices; 
	int cols = vertices;
	
	for(int r=0; r<rows; r++){
		for(int c=0; c<cols; c++){
			cout<<graph[r][c]<<"\t";
		}
		cout<<endl;
	}
}

bool isReachable(int **graph, int *visited, int vertices, int u, int v){

	cout<<"start: "<<u<<" end: "<<v<<endl;
	if(graph[u][v])
		return true;

	for(int start = 0; start < vertices; start++){

		if(visited[start] == 0 && graph[u][start] && u != start){
			visited[start] = 1;
			return isReachable(graph, visited, vertices, start, v);
		}
	}

	return false;

}

bool isReachableIterative(int **graph, int vertices, int u, int v){

	if( graph[u][v])
		return true;

	stack<int> s;
	int visited[vertices];

	memset(visited, 0, vertices*sizeof(int));

	s.push(u);
	visited[u] = 1;

	while(!s.empty()){
		int current = s.top();
		s.pop();
		if(graph[current][v])
			return true;

		for(int start = 0; start < vertices; start++){
			if(visited[start] == 0 && graph[current][start] && current != start){
				visited[start] = 1;
				s.push(start);
			}
		}
	}

	return false;
}










