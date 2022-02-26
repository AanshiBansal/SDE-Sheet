//BFS because shortest path: as soon we find the path, problem solved
//Bitmask
//Time: O((2^n)*(n^2)) (2^n)*n total states and each state can have n neighbors
//Space: O((2^n)*n)
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n<2)
            return 0;
        int endingMask=(1<<n)-1;
        //state consists of mask and node
        set<pair<int,int>>s;
        int ans=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            int currMask=(1<<i);
            q.push({currMask,i});
            s.insert({currMask,i});
        }
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int currMask=q.front().first;
                int currNode=q.front().second;
                //cout<<currMask<<" "<<currNode<<endl;
                q.pop();
                for(int node:graph[currNode]){
                    int nextMask=currMask|(1<<node);
                    if(nextMask==endingMask)
                        return ans+1;
                    if(s.find({nextMask,node})==s.end()){
                        s.insert({nextMask,node});
                        q.push({nextMask,node});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
