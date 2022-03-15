class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int a=text1.size();
        int b=text2.size();
        vector<vector<int> >dp(a+1,vector<int>(b+1));
        for(int i=0;i<=a;i++)
            dp[i][0]=0;
        for(int j=0;j<=b;j++)
            dp[0][j]=0;
        for(int i=1;i<=a;i++)
            for(int j=1;j<=b;j++)
                dp[i][j]=(text1.at(i-1)==text2.at(j-1))?dp[i-1][j-1]+1:max(dp[i-1][j],dp[i][j-1]);
               
        return dp[a][b]; 
    }
};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int a=text1.size();
        int b=text2.size();
        if(a<b)
            return longestCommonSubsequence(text2, text1);
        vector<int>dp(b+1,0);
        vector<int>curr(b+1);
        for(int i=1;i<=a;i++){
            curr[0]=0;
            for(int j=1;j<=b;j++)
                curr[j]=(text1.at(i-1)==text2.at(j-1))?dp[j-1]+1:max(dp[j],curr[j-1]);
            dp=curr;
        }      
        return dp[b];
    }
};