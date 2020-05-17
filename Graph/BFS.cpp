#include<bits/stdc++.h>
using namespace std;

//creating graph as adjacency list
void addEdge(vector<int> adj[], int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void BFS(vector<int> adj[], int V, int source){
	bool visited[V]; //only visit unvisited nodes
	for(int i=0; i<V; i++){ //mark all nodes as unvisited
        visited[i] = false;
    }
	queue<int> q;
	
	q.push(source);
	visited[source] = true; 
	
	while(!q.empty()){
		cout<<q.front()<<" "; //print the front element of queue
		for(auto x:adj[q.front()]){
			if(!visited[x]){
				q.push(x);
				visited[x] = true; //mark as visited as a node is pushed to queue
			}
		}
		q.pop();
	}
}

int main(){
	int vertices, edges;
	cin>>vertices>>edges;
	
	vector<int> adj[vertices];
	int count = 0, node1, node2, source;
	while(count<edges){
		cin>>node1>>node2;
		addEdge(adj, node1, node2);
		count++;
	}
	cout<<"Enter the source node: ";
	cin>>source;
	
	BFS(adj, vertices, source);
}
