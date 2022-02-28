// DFS
// Time: O(V+E)
// Space: O(V)
class Solution {
  private:
    bool dfs(vector<int> adj[], vector<bool>&vis,  vector<bool>&currVis, int node, int parent){
        for(int neighbor: adj[node]){
            if(neighbor!=parent){
                if(currVis[neighbor])
                    return true;
                vis[neighbor]=true;
                currVis[neighbor]=true;
                int res=dfs(adj, vis, currVis, neighbor, node);
                if(res)
                    return true;
                currVis[neighbor]=false;
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<int> adj[]) {
        // code here
        if(V==0)
            return false;
        vector<bool>vis(V,false);
        vector<bool>currVis(V,false);
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                vis[i]=true;
                currVis[i]=true;
                if(dfs(adj,vis,currVis,i,-1))
                    return true;
                currVis[i]=false;
            }
        }
        return false;
    }
};

// BFS
// Time: O(V+E)
// Space: O(V)
class Solution {
  private:
    bool bfs(vector<int> adj[], vector<bool>&vis, int node){
        vis[node]=true;
        queue<pair<int,int>>q;
        q.push({node,-1});
        while(!q.empty()){
            int curr=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(int neighbor: adj[curr]){
                if(neighbor!=parent){
                    if(vis[neighbor])
                        return true;
                    vis[neighbor]=true;
                    q.push({neighbor,curr});
                }
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<int> adj[]) {
        // code here
        if(V==0)
            return false;
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                if(bfs(adj,vis,i))
                    return true;
            }
        }
        return false;
    }
};

// Union Find
// Time: O(E) O(Eα(V))≈O(E) as O(α(V)) is approximately 1
// https://leetcode.com/problems/redundant-connection/solution/
// Space: O(V)
struct disjointSet{
    vector<int>parent;
    vector<int>rank;
    disjointSet(int n){
        parent=vector<int>(n);
        rank=vector<int>(n,0);
        for(int i=0;i<n;i++)
            parent[i]=i;
    };
    int find(int v){
        if(v==parent[v])
            return v;
        parent[v]=find(parent[v]);
        return parent[v];
    };
    void unionSet(int a, int b){
        if(rank[a]<rank[b])
            parent[a]=b;
        else{
            if(rank[a]>rank[b])
                parent[b]=a;
            else{
                rank[a]++;
                parent[b]=a;
            }
        }
    };
};
class Solution {
  public:
    bool isCycle(int V, vector<int> adj[]) {
        if(V==0)
            return false;
        disjointSet dsu=disjointSet(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                // Consider each edge only once
                if(i<=adj[i][j]){
                    int rootA=dsu.find(i);
                    int rootB=dsu.find(adj[i][j]);
                    if(rootA==rootB)
                        return true;
                    dsu.unionSet(rootA, rootB);
                }
            }
        }
        return false;
    }
};