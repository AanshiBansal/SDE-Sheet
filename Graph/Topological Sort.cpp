// Directed Acyclic Graph

// Kahn's Algorithm
// Time: O(V+E)
// Space: O(V)
// BFS 
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>indegree(V,0);
	    for(int i=0;i<V;i++){
	        for(int neighbor:adj[i]){
	            indegree[neighbor]++;
	        }
	    }
	    queue<int>q;
	    vector<int>ans;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0)
	            q.push(i);
	    }
	    while(!q.empty()){
	        int front=q.front();
	        q.pop();
	        ans.push_back(front);
	        for(int neighbor:adj[front]){
	            indegree[neighbor]--;
	            if(indegree[neighbor]==0)
	                q.push(neighbor);
	        }
	    }
	    return ans;
	}
};

// Time: O(V+E)
// Space: O(V)
// DFS
class Solution
{
    private:
    void dfs(vector<int> adj[], int node, vector<bool>&vis, stack<int>&s){
        vis[node]=true;
        for( int neighbor: adj[node]){
            if(vis[neighbor]==false){
                dfs(adj,neighbor,vis,s);
            }
        }
        s.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int>s;
	    vector<int>ans;
	    vector<bool>vis(V,false);
	    for(int i=0;i<V;i++){
	        if(vis[i]==false)
	            dfs(adj,i,vis,s);
	    }
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}
};