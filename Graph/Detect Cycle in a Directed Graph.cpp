class Solution {
  private:
    bool dfs(vector<int> adj[], vector<bool>&vis,  vector<bool>&currVis, int node){
        for(int neighbor: adj[node]){
            if(currVis[neighbor])
                return true;
            currVis[neighbor]=true;
            if(vis[neighbor]==false){
                vis[neighbor]=true;
                int res=dfs(adj, vis, currVis, neighbor);
                if(res)
                    return true;
            }
            currVis[neighbor]=false;
        }
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        if(V==0)
            return false;
        vector<bool>vis(V,false);
        vector<bool>currVis(V,false);
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                vis[i]=true;
                currVis[i]=true;
                if(dfs(adj,vis,currVis,i))
                    return true;
                currVis[i]=false;
            }
        }
        return false;
    }
};