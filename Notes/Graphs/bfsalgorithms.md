


```cpp

#include<bits/stdc++.h> 
using namespace std ;

class Graph{
 
  int V ;
  vector<vector<int>> adj;
  public : 
  Graph(int V) ; // constructor
  // function to add an edge to the graph
  void addEdge(int v , int u) ; 
  // function to do bfs traversal from a given source
  void bfs(int source) ;

};

Graph::Graph(int V){
	this->V = V ;
	adj.resize(V) ;
}
void Graph::addEdge(int v, int u)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void Graph::bfs(int source){
	// mark all the vertices as not visited 
	vector<bool> visited(V , false) ;
	// create a queue a bfs 
	queue<int> q ;
	visited[source] = true ;
	q.push(source) ;

	while(!q.empty()){
		// dequeue a vertex from queue
		int u= q.front() ;
		cout<<u<<" "<<endl ;
		q.pop() ;
		for(auto v : adj[u]){
			if(!visited[v]){
				visited[v] = true ;
				q.push(v) ;
			}
		}
	}


}

int main(){
	int n, m;
    cin >> n >> m;
    // adjacency list for undirected graph
    // time complexity: O(2E)

    Graph g(n) ;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u , v) ;
    }
    int start ;
    cin>> start ;

    g.bfs(2) ;


	return 0 ;
}

```