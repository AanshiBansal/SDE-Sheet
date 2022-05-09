//Time: O(n)
//Space: O(n)
// https://leetcode.com/problems/jump-game-iv/
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if(n<=1)
            return 0;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){                             //O(n)
            mp[arr[i]].push_back(i);
        }
        vector<bool>vis(n,false);                        //O(n)
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0]=true;
        while(!q.empty()){
            pair<int,int>top=q.front();
            q.pop();
            int reach=top.first;
            int index=top.second;
            if(index==n-1)
                return reach;
            if(index-1>=0 && vis[index-1]==false){
                vis[index-1]=true;
                q.push({reach+1,index-1});
            }
            if(vis[index+1]==false){
                vis[index+1]=true;
                q.push({reach+1,index+1});
            }
            for(int num:mp[arr[index]]){
                if(vis[num]==false){
                    vis[num]=true;
                    q.push({reach+1,num});
                }
            }
            mp.erase(arr[index]);                       //Imp condition to make it O(n)
        }
        return INT_MAX;
    }
};