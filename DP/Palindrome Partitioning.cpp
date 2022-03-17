class Solution{
private:
    bool isPalindrome(string &str, int low, int high){
        while(low<high){
            if(str[low++]!=str[high--])
            return false;
        }
        return true;
    }
    int util(string &str, int low, int high, vector<vector<int>>&dp){
        if(dp[low][high]!=INT_MAX)
            return dp[low][high];
        if(isPalindrome(str,low,high)){
            return dp[low][high]=0;
        }
        int ans=INT_MAX;
        for(int i=low;i<high;i++){
            ans=min(ans,1+util(str,low,i,dp)+util(str,i+1,high,dp));
        }
        return dp[low][high]=ans;
    }
public:
    int palindromicPartition(string str)
    {
        int n=str.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        return util(str,0,n-1,dp);
    }
};