You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.
If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
Return the maximum coins you can collect by bursting the balloons wisely.

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

class Solution {
private:
    vector<vector<int>>mp;
    int dp(vector<int>&nums, int start, int end, int n, int left, int right){
        if(start<0 || end>=n || start>end)
            return 0;
        if(mp[start][end]!=-1)
            return mp[start][end];
        int ans=0;
        for(int i=start;i<=end;i++){
            ans=max(
                    ans,
                    dp(nums,start,i-1,n,left,nums[i]) +left*nums[i]*right +dp(nums,i+1,end,n,nums[i],right)
                );
        }
        mp[start][end]=ans;
        return ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        mp=*new vector<vector<int>>(n,vector<int>(n,-1));
        return dp(nums,0,n-1,n,1,1);
    }
};

//Time: O(n^3)
//Space: O(n^2)
