class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int> >dp(m+1,vector<int>(n+1));
        for(int i=0;i<=m;i++)
            dp[i][0]=i;
        for(int j=0;j<=n;j++)
            dp[0][j]=j;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
        return dp[m][n];
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        if(n>m)
            minDistance(word2,word1);
        vector<int>dp(n+1);
        for(int j=0;j<=n;j++)
            dp[j]=j;
        vector<int>curr(n+1);
        for(int i=1;i<=m;i++){
            curr[0]=i;
            for(int j=1;j<=n;j++)
                if(word1[i-1]==word2[j-1])
                    curr[j]=dp[j-1];
                else
                    curr[j]=1+min(dp[j-1],min(dp[j],curr[j-1]));
            dp=curr;
        }
        return dp[n];
    }
};