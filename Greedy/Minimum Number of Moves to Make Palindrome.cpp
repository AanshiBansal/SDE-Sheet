// https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/
// Greedy Approach and 2-pointer approach
// Time: O(n^2)
// Space: O(1)
class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int ans=0;
        int left=0;
        int right=s.size()-1;
        while(left<right){
            int r=right;
            while(s[left]!=s[r]){
                r--;
            }
            if(r==left){
                swap(s[left],s[left+1]);
                ans++;
                continue;
            }
            while(r<right){
                swap(s[r],s[r+1]);
                r++;
                ans++;
            }
            left++;
            right--;
        }
        return ans;
    }
};