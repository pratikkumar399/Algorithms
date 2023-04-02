**Topological Sort**
* Topological sort means linear ordering of the graph 
* In this every node that occurs before a node in the graph must occur before its next node in the linear ordering of the graph .
* only valid for directed acyclic graphs
* if a graph contains cycle then if cannot have topological sort .

> We will be using a dfs traversal to find the topological sort 

 * So the intuition is that after the completion of th dfa call for a node , when we backtrack we will add that node in the stack
and this will make sure that the nodes are added in the linear order of their apprearance .

Code for it 👍

```cpp
class Solution
{
	public:
	
	void topologicalSortDfs(int node , vector<int> &visited , vector<int> adj[] , stack<int> &st){
	    visited[node] = 1 ;
	    
	    for(auto it : adj[node]){
	        if(visited[it] == 0){
	            topologicalSortDfs(it,visited,adj,st) ;
	        }
	    }
	        st.push(node) ;
	    
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> visited(V, 0);
	    stack<int> st ;
	    
	    for(int i = 0 ; i<V ;i++){
	        if(!visited[i]){
	            topologicalSortDfs(i,visited,adj,st) ;
	        }
	    }
	    
	   vector<int> ans ;
	   while(!st.empty()){
	       int topo =  st.top() ;
	       st.pop() ;
	       
	       ans.push_back(topo) ;
	       
	   }
	    return ans ;
	}
};

```