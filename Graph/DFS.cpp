// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

// DFS
// Time: O(V+E)
// Space: O(V)
class Solution {
  private:
    void dfsUtil(vector<int> adj[], vector<bool>&vis, vector<int>&dfs, int curr){
        for(int neighbor: adj[curr]){
            if(vis[neighbor]==false){
                vis[neighbor]=true;
                dfs.push_back(neighbor);
                dfsUtil(adj,vis,dfs,neighbor);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>dfs;
        if(V==0)
            return dfs;
        vector<bool>vis(V,false);
        dfs.push_back(0);
        vis[0]=true;
        dfsUtil(adj, vis, dfs, 0);
        return dfs;
    }
};