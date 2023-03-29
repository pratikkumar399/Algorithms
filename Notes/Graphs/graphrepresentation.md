>  So there are two ways to represent a graph 
  + Adjacency List 
  + Adjacency Matrix

#### Adjacency List

👍 Adjacency List basically is a list of adjacent vertices connected to the current vertex 


### Adjacency Matrix 
👍 Adjacency Matrix is simply a 2d matrix of size n * m , where n and m are the number of vertices in the graph and graph[i][j] = 1 , means that there is a connecteion between vertex i and vertex j. 

Graph Representation :) 
```cpp
#include<bits/stdc++.h> 
using namespace std ;



int main(){
	int n, m;
    cin >> n >> m;
    // adjacency list for undirected graph
    // time complexity: O(2E)
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // for adjacent matrix  
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1 ;
        adj[v][u] = 1 ;
    }
    
   for(int i = 0 ; i < n ; i++){
      cout<<i<<"->" ;
      for(int j = 0 ; j < adj[i].size() ; j++){
        cout<<adj[i][j]<<"," ;
      }
      cout<<endl ;
   }
	return 0 ;
}	    

```