class Solution{
	public:
	int maxSumIS(int nums[], int n)  
	{  
	    // Your code goes here
	    vector<int>dp(n);
	    dp[0]=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++){
            dp[i]=nums[i];
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+nums[i]);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
	}  
};