> Arrival time is the entry time of a node.
> Departure time is the time when the processing of the node was completed


Code 👍

```cpp

#include<bits/stdc++.h> 
using namespace std ;


void dfs(int src , vector<vector<int>> &adj,vector<int> &arrival, 
 vector<int> &departure, vector<int> &visited,int time ){
    // increase the entry time upon arriving at the node
	arrival[src]= ++time;

	visited[src]=1;

	for(int node : adj[src]){
		if(visited[node] == 0){
			dfs(node,adj,arrival,departure,visited,time);
		}
	}
    // increase the departure time after procssing the node
	departure[src]= ++time;

}

int main(){
	
	int n;
	cin>>n;

	vector<vector<int>> adj(n+1);
	vector<int> arrival(n);
	vector<int> departure(n);

	for(int i = 0 ; i< n ;i++){
		int u , v ; 
		cin>>u>>v, adj[u].push_back(v), adj[v].push_back(u);
	}

	vector<int> visited(n , 0);
	int time=-1;
	int connected =0;

	for(int i = 0 ; i< n ; i++){

		if(visited[i] == 0){
			dfs(i , adj , arrival , departure , visited , time);
			connected++;
		}
	}

	cout<<"connected components : "<<connected<<endl;

	for(int i=0; i< n ;i++){
		cout<<"Vertex " <<i << " " << arrival[i]<<" "<<departure[i]<<endl;
	}



	return 0 ;
}
```