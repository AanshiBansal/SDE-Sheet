// https://leetcode.com/problems/remove-duplicate-letters/
// Time: O(n)
// Space: O(n)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>mp(26,0);
        vector<bool>vis(26,false);
        for(int i=0;i<s.size();i++){
            mp[s[i]-'a']++;
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(vis[s[i]-'a']==false){
                while(!ans.empty() && ans.back()>s[i] && mp[ans.back()-'a']>0){
                    vis[ans.back()-'a']=false;
                    ans.pop_back();
                }
                vis[s[i]-'a']=true;
                ans.push_back(s[i]);
            }
            mp[s[i]-'a']--;
        }
        return ans;
    }
};