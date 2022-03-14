class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        DisjointSet ds=DisjointSet(V);
        int ans=0;
        vector<vector<int>>edges;
        for(int i=0;i<V;i++){
            for(auto neighbor:adj[i]){
                edges.push_back({neighbor[1],i,neighbor[0]});
            }
        }
        sort(edges.begin(),edges.end());
        for(auto edge: edges){
            int u=edge[1];
            int v=edge[2];
            int cost=edge[0];
            if(ds.find(u)!=ds.find(v)){
                ans+=cost;
                ds.unionSet(u,v);
            }
        }
        return ans;
    }
};