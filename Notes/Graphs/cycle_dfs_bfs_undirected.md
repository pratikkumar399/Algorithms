## Cycle detection In Undirected Graph

▶️ Using DFS algorithm  

**Concept**

    > For finding a cycle in undirected graph , be it any of dfs or bfs traversals, we have to maintain a visited array.
    > Now when we do the traversal, and find the adjacent node of the current node already visited, then the case of the cycle arises : 
        👍It is a cycle if and only if the adjacent node has already been visited and is not the parent of the current node. 


## DFS algorithm

```cpp
    class Solution {
  public:
  bool isCycle_Check(int vertex , int parent ,vector<int> adj[] , vector<int>& visited){
      
      visited[vertex] = true ;
      
      for(auto it: adj[vertex]){
          if(visited[it]==0){
              if(isCycle_Check(it, vertex , adj ,visited))
              return true ;
          }  
          else if(it != parent) return true ;
      }
      
      return false ;
  }
  
  
  public : 
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> visited(V+1,0) ;
        
        for(int i = 0 ; i < V ;i++){
            if(!visited[i]){
                if(isCycle_Check(i ,-1 ,adj ,visited )) return true ;
            }
        }
        return false ;
    }
};
```

### BFS algorithm

```cpp
#include<bits/stdc++.h> 
using namespace std ;


// lets do a bfs traversal
// now if in the traversal if we find a node that has been visited and is not the parent 
// of the current node then we can say that yes we have found a cycle in the graph

bool detect(int source , vector<vector<int>> &graph , vector<int> &visited){

	// mark the current node as visited 
	visited[source] = 1 ;
	// make a queue which stores the pair of current node and its parent node 
	queue<pair<int, int>> q ;
	// store the first node along with its parent as -1
	q.push({source , -1}) ;
	while(!q.empty()){
		// current node
		int node = q.front().first ;
		// parent node
		int parent = q.front().second ;
		// after traversing the current node make sure that we pop out the node 
		// this ensures that we do not visit that node again
		q.pop();

		// now go in the current node and find its adjacent node
		for(auto adjacentNode : graph[node]){
			// if the adjacent node has not been visited then mark it as visited 
			if(!visited[adjacentNode]){
				visited[adjacentNode] = 1 ;
				q.push({adjacentNode , node}) ;
			}
			// now if the adjacent node has been visited and it is not the parent node 
			// then surely this means that we have a cycle present in the graph
			else if(parent != adjacentNode){
				// so return true if there is a cycle
				return true ;
			}
		}
	}

	return false ;
}



bool bfs(vector<vector<int>> &graph , int m ){
	vector<int> visited(graph.size() + 1, 0) ;
	for(int i = 0 ; i < graph.size() ; i++){
		if(!visited[i]){
			if(detect(i , graph , visited)) return true ;
		}
	}

	return false ;
}

int main(){
	int n , m ;
	cin >> n >> m ;
  	
  	vector<vector<int>> graph(n+1) ;
  	 
	for(int i = 0 ; i < m ; i++){
		int u , v ;
		cin >> u >>v ;
		graph[u].push_back(v) ;
		graph[v].push_back(u) ;
	}

	cout<<bfs(graph , m)<<endl  ;



	return 0 ;
}
```