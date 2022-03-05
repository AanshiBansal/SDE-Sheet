class Solution {
private:
    void dfs(vector<vector<int>>& adj, vector<bool>&vis, vector<int>&low, vector<int>&tin, int node, int parent, vector<int>&points, int &time){
        vis[node]=true;
        low[node]=time;
        tin[node]=time;
        time++;
        int count=0;
        for(int neighbor:adj[node]){
            if(neighbor==parent)
                continue;
            if(vis[neighbor]==false){
                count++;
                dfs(adj,vis,low,tin,neighbor,node,points,time);
                if(low[neighbor]>=tin[node] && parent!=-1)
                    points.push_back(node);
            }
            low[node]=min(low[node],low[neighbor]);
        }
        if(count>1 && parent==-1)
            points.push_back(node);
    }
public:
    int minDays(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].size();
        vector<vector<int>>adj(m*n,vector<int>());
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        int islands=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    islands++;
                    for(int k=0;k<4;k++){
                        if(i+dy[k]>=0 && i+dy[k]<m && j+dx[k]>=0 && j+dx[k]<n && grid[i+dy[k]][j+dx[k]]==1)
                            adj[i*n+j].push_back((i+dy[k])*n+(j+dx[k]));
                    }
                }
            }
        }
        if(islands<=1)
            return islands;
        vector<bool>vis(m*n,false);
        vector<int>low(m*n);
        vector<int>tin(m*n);
        vector<int>points;
        int time=0;
        int count=0;
        for(int i=0;i<n*m;i++){
            if(vis[i]==false && grid[i/n][i%n]==1){
                if(count>0)
                    return 0;
                count++;
                dfs(adj,vis,low,tin,i,-1,points,time);
            }
        }
        // for(int i=0;i<m*n;i++){
        //     cout<<i<<" "<<tin[i]<<" "<<low[i]<<endl;
        // }
        if(points.size()>0)
            return 1;
        return 2;
    }
};

// https://leetcode.com/discuss/general-discussion/709997/questions-based-on-articulation-points-and-bridgess