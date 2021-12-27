//BFS using queue
//Space: O(V)
//Time: O(V+E)
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int size=graph.size();
        vector<int>color(size,0);
        for(int j=0;j<size;j++){
            if(color[j]==0){
                queue<int>q;
                q.push(j);
                color[j]=1;
                while(!q.empty()){
                    int curr=q.front();
                    q.pop();
                    int neighbor;
                    if(color[curr]==1)
                        neighbor=2;
                    else
                        neighbor=1;
                    for(int i=0;i<graph[curr].size();i++){
                        if(color[graph[curr][i]]==0){
                            color[graph[curr][i]]=neighbor;
                            q.push(graph[curr][i]);
                        }else{
                            if(color[graph[curr][i]]!=neighbor){
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};

//DFS using Auxillary Array
//Space: O(v)
//Time: O(V+E)
class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int v, vector<int>&color){
        int neighbor;
        if(color[v]==1)
            neighbor=2;
        else
            neighbor=1;
        for(int i=0;i<graph[v].size();i++){
            if(color[graph[v][i]]==0){
                color[graph[v][i]]=neighbor;
                bool ans=dfs(graph, graph[v][i], color);
                if(ans==false)
                    return false;
            }else{
                if(color[graph[v][i]]!=neighbor)
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int size=graph.size();
        vector<int>color(size,0);
        for(int j=0;j<size;j++){
            if(color[j]==0){
                color[j]=1;
                bool ans=dfs(graph,j,color);
                if(ans==false)
                    return false;
            }
        }
        return true;
    }
};