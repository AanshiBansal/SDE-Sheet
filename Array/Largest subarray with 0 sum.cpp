//Time: O(n)
//Space: O(n)
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int>mp;
        mp[0]=0;
        int sum=0;
        int ans=0;
        for(int i=0;i<A.size();i++){
            sum+=A[i];
            if(mp.find(sum)!=mp.end()){
                ans=max(ans,i+1-mp[sum]);
            }else{
                mp[sum]=i+1;
            }
        }
        return ans;
    }
};