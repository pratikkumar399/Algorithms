### Dijkstra algorithm

> This is an algorithm which helps to find the shortest path between two points in a graph.


> Time complexity is O(E logV) 

> We will use  a MIN priority queue to implement this algorithm

* There will be a distance array which will store the distance of adjacent node from current node
* Initially all the nodes will be marked with distance of infinity except the source node .
* Now  push the source node in the priority queue along with the distance zero , becuase the distance of source node with itself is zero.
* Take out the ditance and current node from the queue 
* Now check if the adjacent nodes have ditance greater than the distance from the current node 
* store the minimum dist and weight in the priority queue.


Code for this algorithm : 


```cpp
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {

        // Create a priority queue for storing the nodes as a pair {dist,node}
        // where dist is the distance from source to the node. 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // initialize the vector with max distance from source , so that 
        // initailly they are univisted 
        vector<int> distTo(V, INT_MAX);

        // Source initialised with dist=0.
        distTo[S] = 0;
        pq.push({0, S});

        // Now, pop the minimum distance node first from the min-heap
        // and traverse for all its adjacent nodes.
        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            // Check for all adjacent nodes of the popped out
            // element whether the prev dist is larger than current or not.
            for (auto it : adj[node])
            {
                int v = it[0];
                int w = it[1];
                if (dis + w < distTo[v])
                {
                    distTo[v] = dis + w;
    
                    // If current distance is smaller,
                    // push it into the queue.
                    pq.push({dis + w, v});
                }
            }
        }
        // Return the list containing shortest distances
        // from source to all the nodes.
        return distTo;
    }
};

```