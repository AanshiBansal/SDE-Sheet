// Greedy Algorithm
// Time: O((N+E)*log(N))
// Space: O(N)

// Undirected
// weighted
// Connected
// Cycles, negative edges, negative cycles dont matter

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int ans=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>dist(V,INT_MAX);
        vector<int>vis(V,false);
        dist[0]=0;
        vis[0]=true;
        for(auto neighbor:adj[0]){
            pq.push({neighbor[1],neighbor[0]});
            dist[neighbor[0]]=neighbor[1];
        }
        int count=1;
        while(count<V){
            pair<int,int>edge=pq.top();
            pq.pop();
            int node=edge.second;
            int cost=edge.first;
            if(vis[node]==false){
                count++;
                ans+=cost;
                vis[node]=true;
                for(auto neighbor:adj[node]){
                    if(vis[neighbor[0]]==false && dist[neighbor[0]]>neighbor[1]){
                        pq.push({neighbor[1],neighbor[0]});
                        dist[neighbor[0]]=neighbor[1];
                    }
                }
            }
        }
        return ans;
    }
};