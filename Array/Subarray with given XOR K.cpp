//Time: O(n)
//Space: O(n)
//XOR(A) ^ XOR(A-B) = XOR(B)  XOR(A-B)==K
//XOR(A) ^ K = XOR(B)
//XOR(A) ^ K ^ K = XOR(B) ^ K
//XOR(A) = XOR(B) ^ K
int Solution::solve(vector<int> &A, int B) {
    int ans=0;
    unordered_map<int,int>mp;
    mp[0]=1;
    int currXOR=0;
    for(int i=0;i<A.size();i++){
        currXOR^=A[i];
        int temp=currXOR^B;
        if(mp.find(temp)!=mp.end())
            ans+=mp[temp];
        mp[currXOR]++;
    }
    return ans;
}