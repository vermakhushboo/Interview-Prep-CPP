/* Detecting cycle in Graph */
/* We will use DFS. DFS of connected graph produces a tree. */
/* For every vertex 'v', if there is an adjacent vertex 'u' that is already visited and is not a parent of 'v', then there is a cycle in the graph */

#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	vector<int> *adj;
	bool isCyclicUtil(int v, bool visited[], bool *recursive_stack);
	
	public:
		Graph(int V);
		void addEdge(int u, int v);
		bool isCyclic();
};

Graph::Graph(int V){
	this->V = V;
	adj = new vector<int>[V];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v); //directed graph
}

bool Graph::isCyclicUtil(int v, bool visited[], bool *recursive_stack){
	if(!visited[v]){
		visited[v] = recursive_stack[v] = true;
		for(auto i : adj[v]){
			if(!visited[i] && isCyclicUtil(i, visited, recursive_stack))
				return true;
			else if(recursive_stack[i])
				return true;
		}
	}
	recursive_stack[v] = false;
	return false;
}

bool Graph::isCyclic(){
	bool *visited = new bool[V];
	bool *recursive_stack = new bool[V];
	for(int i=0; i<V; i++){
		visited[i] = recursive_stack[i] = false;
	}
	for(int i=0; i<V; i++){
		if(isCyclicUtil(i, visited, recursive_stack))
			return true;
	}
	return false;
}

int main(){
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}
