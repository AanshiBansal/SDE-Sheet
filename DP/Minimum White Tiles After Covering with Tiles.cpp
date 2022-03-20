// Recursion with Memorization
// Top Down DP
// Time: O(numCarpets*floor.size())
// Space: O(numCarpets*floor.size())
class Solution {
private:
    vector<int>count;
    vector<vector<int>>mp;
    int carpetLen;
    int numCarpets;
    string floor;
    int n;
    int rec(int index, int carpetsUsed){
        if(index>=n)
            return 0;
        if(carpetsUsed==numCarpets)
            return count[index];
        if(mp[index][carpetsUsed]!=-1)
            return mp[index][carpetsUsed];
        int first=(floor[index]=='1'?1:0)+rec(index+1,carpetsUsed);
        int second=rec(index+carpetLen,carpetsUsed+1);
        return mp[index][carpetsUsed]=min(first,second);
    }
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        n=floor.size();
        mp =vector<vector<int>>(n,vector<int>(numCarpets+1,-1));
        count = vector<int>(n,0);
        this->floor=floor;
        this->numCarpets=numCarpets;
        this->carpetLen=carpetLen;
        count[n-1]=floor[n-1]=='1'?1:0;
        for(int i=n-2;i>=0;i--){
            count[i]=count[i+1];
            if(floor[i]=='1')
                count[i]++;
        }
        return rec(0,0);
    }
};

// Tabulatiom
// Bottom Up DP
// Time: O(numCarpets*floor.size())
// Space: O(numCarpets*floor.size())
class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n=floor.size();
        vector<vector<int>>dp(numCarpets+1,vector<int>(n+1,0));
        int curr=0;
        for(int i=0;i<n;i++){
            if(floor[i]=='1')
                curr++;
            dp[0][i+1]=curr;
        }
        for(int i=1;i<=numCarpets;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=dp[i][j-1]+floor[j-1]-'0';
                if(j-carpetLen>=0){
                    dp[i][j]=min(dp[i][j],dp[i-1][j-carpetLen]);
                }else
                    dp[i][j]=0;
            }
        }
        return dp[numCarpets][n];
    }
};

// Space Optmisation
// Bottom Up DP
// Time: O(numCarpets*floor.size())
// Space: O(floor.size())
class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n=floor.size();
        vector<int>dp(n+1);
        dp[0]=0;
        vector<int>temp(n+1);
        int curr=0;
        for(int i=0;i<n;i++){
            if(floor[i]=='1')
                curr++;
            dp[i+1]=curr;
        }
        for(int i=1;i<=numCarpets;i++){
            temp[0]=0;
            for(int j=1;j<=n;j++){
                temp[j]=temp[j-1]+floor[j-1]-'0';
                if(j-carpetLen>=0){
                    temp[j]=min(temp[j],dp[j-carpetLen]);
                }else
                    temp[j]=0;
            }
            dp=temp;
        }
        return dp[n];
    }
};