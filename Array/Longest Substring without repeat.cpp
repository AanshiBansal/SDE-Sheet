//Time: O(n)
//Space: O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int start=-1;
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(mp.find(s[i])==mp.end()||mp[s[i]]<=start){
                mp[s[i]]=i;
            }else{
                ans=max(ans,i-1-start);
                start=mp[s[i]];
                mp[s[i]]=i;
            }
        }
        return max(ans,n-1-start);
    }
};