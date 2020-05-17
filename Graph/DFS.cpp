#include<bits/stdc++.h>
using namespace std;

class Graph{
	int vertices;
	vector<int> *adj;
	void DFS_Util(int source, bool visited[]); //private helper function
	
	public:
		//Graph constructor
		Graph(int V){
			vertices = V;
			adj = new vector<int>[vertices];
		}
		void addEdge(int u, int v);
		void DFS(int source);
};

void Graph::addEdge(int u, int v){
	adj[u].push_back(v); //creating directed graph
}

void Graph::DFS_Util(int source, bool visited[]){
	cout<<source<<" ";
	visited[source] = true;
	
	for(auto x : adj[source]){
		if(!visited[x]){
			DFS_Util(x, visited);
		}
	}
    // vector<int>::iterator i;
    // for (i = adj[source].begin(); i != adj[source].end(); ++i)
    //     if (!visited[*i])
    //         DFS_Util(*i, visited);
}

void Graph::DFS(int source){
	bool *visited = new bool[vertices];
	//marking all vertices as unvisited initially
	for(int i=0; i<vertices; i++){
		visited[i] = false;
	}
	DFS_Util(source, visited);
}

int main(){
	int vertices;
//	cin>>vertices;
//	Graph g(vertices);
	Graph g(4);
	g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.DFS(2);
}
