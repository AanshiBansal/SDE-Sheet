//Time: O(n^3)
//Space: O(n^2)
//Bottom-Up DB
class Solution {
public:
    int helper(int i, int j, int n, vector<vector<int>>&dp){
        if(i<0 || j<0 || i==n || j==n)
            return 0;
        return dp[i][j];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0)
            return 0;
        int n=grid[0].size();
        if(n==0)
            return 0;
        vector<vector<int>>dp;
		//k signifies the current row of the matrix
        for(int k=m-1;k>=0;k--){
            vector<vector<int>>curr(n,vector<int>(n,0));
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(k!=m-1){
                        for(int x=i-1;x<=i+1;x++)
                            for(int y=j-1;y<=j+1;y++)
                                curr[i][j]=max(curr[i][j],helper(x,y,n,dp));
                    }
                    curr[i][j]+=grid[k][i];
                    if(i!=j)
                        curr[i][j]+=grid[k][j];
                }
            }
            dp=curr;
        }
        return dp[0][n-1];
    }
};