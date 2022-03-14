// Directed (For undirected convert to directed, if -ve edge is present then it will become -ve cycle)
// Weighted 
// Handles negative edges
// Handles cycles
// Detects negative cycle (practically not possible to find shortest path in this scenario)
// Dynamic Programming

class Solution{
	public:
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        vector<int>dist(V,INT_MAX);
        dist[S]=0;
        for(int i=0;i<V-1;i++){
            for(auto edge:adj){
                int u=edge[0];
                int v=edge[1];
                int w=edge[2];
                if(dist[u]!=INT_MAX && dist[u]+w<dist[v])
                    dist[v]=dist[u]+w;
            }
        }
        return dist;
    }
};