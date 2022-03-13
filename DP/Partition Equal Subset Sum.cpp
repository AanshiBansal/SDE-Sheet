// https://leetcode.com/problems/partition-equal-subset-sum/
// 0-1 Knapsack
// Time: O(n*sum)
// Space: O(sum)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums)
            sum+=num;
        if(sum%2!=0)
            return false;
        sum/=2;
        vector<bool>dp(sum+1,false);
        dp[0]=true;
        for(int num:nums){
            for(int i=sum;i>=0;i--){
                if(i-num>=0 && dp[i-num])
                    dp[i]=true;
            }
            if(dp[sum])
                return true;
        }
        return false;
    }
};