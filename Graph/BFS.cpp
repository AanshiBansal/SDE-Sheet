// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

//BFS
// Time: O(V+E)
// Space: O(V)

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>bfs;
        if(V==0)
            return bfs;
        vector<bool>vis(V,false);
        vis[0]=true;
        bfs.push_back(0);
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(int neighbor: adj[front]){
                if(vis[neighbor]==false){
                    vis[neighbor]=true;
                    bfs.push_back(neighbor);
                    q.push(neighbor);
                }
            }
        }
        return bfs;
    }
};