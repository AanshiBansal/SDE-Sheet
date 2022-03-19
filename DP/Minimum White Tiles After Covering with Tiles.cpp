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