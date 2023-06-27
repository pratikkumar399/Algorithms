## Bipartite Graph

* An undirected graph , is called bipartite graph if the vertices of the graph can be divided into two disjoint sets U and V such that there is a one to one mapping between the edges of the two sets.

* Another way of looking at this would mean that if there is a graph such that every adjacent node of the graph has differnt colors then the graph is a bipartite graph.
  
* Coditions for a bipartite graph: 
   * All the adjacent nodes have different colors
   * If there is a cycle in the graph and it is of odd length then the graph cannot be a bipartite graph.
   * Any acyclic graph is a bipartite graph

> So the simple condition is that if there is a vertex that has the same color as its parent node then the graph is not a bipartite graph.

> Lets see bipartite graph in dfs : 

```cpp
class Solution {
public:
  
   bool dfs(int n , vector<int> &visited , vector<vector<int>> &graph){
      if(!visited[n]) !visited[n] ;
      for(auto it :  graph[n]){
         if(!visited[it]){
            visited[it] = !visited[n];
            if(!dfs(it , visited ,graph)) {
            return false ;
            }
         }
         else if(visited[it] == visited[n] ){
            return false ;
         }
      }
      return true ; 
   }

   bool isBipartite(vector<vector<int>>& graph) {
   int n = graph.size() ;
      vector<int> visited(n,0) ;      
      for(int i= 0 ; i< n ;i++){
         if(!visited[i]){
         if(!dfs(i,visited,graph)) return false ;
         }
      }
   return true ;
   }
};
```

> BFS Implementation

```cpp
class Solution {
public:
  
  bool checkBipartite(int n, vector<int> &visited, vector<vector<int>> &graph){
      visited[n] = 1 ;
      queue<int>  q ;
      q.push(n); 

      
      while(!q.empty()){
      int top = q.front() ;
      q.pop() ;
      
      for(auto it : graph[top]){
         if(visited[it] == -1) {
            visited[it] = !visited[top] ;
            q.push(it);
         }else if(visited[it] == visited[top])
         {
            return false ;
         }
      }
      
      }
    
     return true ;
    
  }
    bool isBipartite(vector<vector<int>>& graph) {
      int n = graph.size() ;
      vector<int> visited(n,-1) ;
      
      for(int i= 0 ; i< n ;i++){
         if(visited[i] == -1){
         if(!checkBipartite(i,visited,graph)) return false ;
         }
      }
      return true ;
    }
  
  
};
```