//Time: O(n^3)
//Space: O(n^2)
//Top Down DP
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==0 || grid[0][0]==-1 || grid[n-1][n-1]==-1)
            return 0;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        dp[0][0]=grid[0][0];
        int moves=2*(n-1);
        for(int k=1;k<=moves;k++){
            vector<vector<int>>curr(n,vector<int>(n,-1));
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    int r1=k-i;
                    int r2=k-j;
                    if(r1<0 || r1>=n || r2<0 || r2>=n || grid[r1][i]==-1 || grid[r2][j]==-1)
                        continue;
                    //down-down
                    curr[i][j]=max(curr[i][j],dp[i][j]);
                    //down-right
                    if(j-1>=0)
                        curr[i][j]=max(curr[i][j],dp[i][j-1]);
                    //right-down
                    if(i-1>=0)
                        curr[i][j]=max(curr[i][j],dp[i-1][j]);
                    //right-right
                    if(i-1>=0 && j-1>=0)
                        curr[i][j]=max(curr[i][j],dp[i-1][j-1]);
                    if(curr[i][j]==-1)
                        continue;
                    curr[i][j]+=grid[r1][i];
                    if(i!=j)
                        curr[i][j]+=grid[r2][j];
                }
            }
            dp=curr;
        }
        return max(0,dp[n-1][n-1]);
    }
};