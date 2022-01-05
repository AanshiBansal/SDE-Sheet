class Solution {
private:
    bool isPalindrome(string s){
        int i=0;
        int j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<vector<string>>>dp(n+1);
        dp[n]=vector<vector<string>>(0);
        for(int k=n-1;k>=0;k--){
            for(int i=k;i<s.size();i++){
                string sub=s.substr(k,i-k+1);
                if(isPalindrome(sub)){
                    vector<vector<string>>temp=dp[i+1];
                    if(temp.size()!=0){
                        for(int j=0;j<temp.size();j++){
                            temp[j].insert(temp[j].begin(),sub);
                            dp[k].push_back(temp[j]);
                        }
                    }
                    else{
                        dp[k].push_back({sub});
                    }
                }
            }
        }
        return dp[0];
    }
};