// DP
// Time: O(n^2)
// Space: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        int ans=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};


class Solution {
private:
    void binarySearch(vector<int>&ans,int low, int high, int num){
        if(low>high){
            if(low<ans.size())
                ans[low]=num;
            else
                ans.push_back(num);
            return;
        }
        int mid=(low+high)/2;
        if(ans[mid]<num){
            binarySearch(ans,mid+1,high,num);
        }else{
            binarySearch(ans,low,mid-1,num);
        }
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            binarySearch(ans,0,ans.size()-1,nums[i]);
        }
        return ans.size();
    }
};