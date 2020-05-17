#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v){
	//undirected graph
	adj[u].push_back(v);
	adj[v].push_back(u);
}

//print graph as adjacency list
void printGraph(vector<int> adj[], int vertices){
	for(int i=0; i<vertices; i++){
		//print vertex name
		cout<<"Adjacency List of vertex "<<i<<"\n";
		//printing the elements of the vector representing nodes connected to node i
		for(int x : adj[i]){
			cout<<"->"<<x;
		}
		cout<<"\n";
	}
}

//creating graph as adjacency list
int main(){
	cout<<"Enter the number of vertices: ";
	int vertices;
	cin>>vertices;
	vector<int> adj[vertices];
	int edges;
	cout<<"\nEnter the number of edges: ";
	cin>>edges;
	if(edges>vertices*vertices){
		cout<<"Graph not possible. Number of edges should be less than vertices^2.\n";
		return 0;
	}
	cout<<"\nEnter the nodes which have an edge between them.\n";
	int node1, node2;
	int count = 0;
	while(count<edges){
		cin>>node1>>node2;
		addEdge(adj, node1, node2);
        count++;
	}
	printGraph(adj, vertices);
	return 0;
}
