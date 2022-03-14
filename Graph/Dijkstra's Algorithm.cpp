// Undirected
// weighted
// No negative edges
// Cycle is fine

// Greedy Algorithm
// Time: O((N+E)*log(N))
// Space: O(N)
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>dist(V,INT_MAX);
        dist[S]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,S});
        while(!pq.empty()){
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            if(dist[node]==d){
                for(int i=0;i<adj[node].size();i++){
                    if(dist[adj[node][i][0]]>d+adj[node][i][1]){
                        dist[adj[node][i][0]]=d+adj[node][i][1];
                        pq.push({dist[adj[node][i][0]],adj[node][i][0]});
                    }
                }
            }
        }
        return dist;
    }
};