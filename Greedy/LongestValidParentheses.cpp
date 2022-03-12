https://leetcode.com/problems/longest-valid-parentheses/

// Stack
// Time: O(n)
// Space: O(n)
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        int ans=0;
        st.push(-1);
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    ans=max(ans,i-st.top());
                }
            }
        }
        return ans;
    }
};

// Greedy
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int longestValidParentheses(string s) {
        int left=0;
        int right=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                left++;
            }else{
                right++;
                if(right>left){
                    left=0;
                    right=0;
                }
                if(left==right)
                    ans=max(ans,2*right);
            }
        }
        left=0;
        right=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')'){
                right++;
            }else{
                left++;
                if(left>right){
                    left=0;
                    right=0;
                }
                if(left==right)
                    ans=max(ans,2*left);
            }
        }
        return ans;
    }
};