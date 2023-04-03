#### Khan's Algorithm for topoSort

> Here we are going to talk about Khan's algorithm for toposort
 * We already saw the implementation of the [toposort algorithm using dfs](/Notes/Graphs/topologicalsort.md) .
 * Let's look at the implementation of the toposort algorithm using bfs traversal algorithm .
 * So basicallly the concept is that we will store the indegree of each of the nodes in a indegree vector 
 * If the indegree of any of the node is zero then we push that in the queue
 * Now we will go through the queue
 * Take out the front node of the queue and store that in the answer vector
 * Now, reduce the indegree of the adjacent nodes
 * And in the process if the indegree of any of the nodes is zero then we push that in the queue. 
 * Finally when we return the answer vector , we will have out required answer
 * Now if at any point of time the queue becomes empty and any of the node is still left to traverse then it means that there is a cycle in the graph and therefore its indegree never becomes zero. 

Code for Toposort using Khan's algorithm ⬇️

```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topoSort(vector<vector<int>>& graph, int n) {
    vector<int> inDegree(n, 0);
    queue<int> q;
    vector<int> result;

    // Calculate in-degree for each vertex
    for (int i = 0; i < n; i++) {
        for (auto neighbor : graph[i]) {
            inDegree[neighbor]++;
        }
    }

    // Enqueue vertices with in-degree 0
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Process the vertices in the queue
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        result.push_back(curr);

        // Decrement in-degree of neighbors
        for (auto neighbor : graph[curr]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return result;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Construct the graph
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    // Topological sort
    vector<int> result = topoSort(graph, n);

    // Print the result
    for (auto vertex : result) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}


```