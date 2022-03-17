//Time: O(n)
//Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size=prices.size();
        if(size==0)
            return 0;
        int ans=0;
        int mini=prices[0];
        // Today is the sell day
        for(int i=0;i<size;i++){
            mini=min(mini,prices[i]);
            ans=max(ans,prices[i]-mini);
        }
        return ans;
    }
};