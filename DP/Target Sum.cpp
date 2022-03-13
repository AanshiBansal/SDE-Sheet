// https://leetcode.com/problems/target-sum/
// Time: O(n*sum)
// Space: O(sum)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(2001,0);
        dp[1000]=1;
        for(int i=0;i<n;i++){
            vector<int>curr(2001,0);
            for(int j=0;j<=2000;j++){
                if(dp[j]>0 && j-nums[i]>=0)
                    curr[j-nums[i]]+=dp[j];
                if(dp[j]>0 && j+nums[i]<=2000)
                    curr[j+nums[i]]+=dp[j];
            }
            dp=curr;
        }
        return dp[target+1000];
    }
};