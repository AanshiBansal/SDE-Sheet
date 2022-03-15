// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
// Time: O(n)
// Space: O(n)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int size=s.size();
        vector<bool>flag(size,true);
        stack<int>st;
        for(int i=0;i<size;i++){
            if(s[i]=='(')
                st.push(i);
            if(s[i]==')'){
                if(!st.empty()){
                    st.pop();
                }else
                    flag[i]=false;
            }
        }
        while(!st.empty()){
            int it=st.top();
            st.pop();
            flag[it]=false;
        }
        string ans="";
        for(int i=0;i<size;i++)
            if(flag[i])
                ans+=s[i];
        return ans;
    }
};