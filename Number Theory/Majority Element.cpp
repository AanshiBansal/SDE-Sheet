//Time: O(n)
//Space: O(1)
//  Boyer-Moore Voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int ans=0;
        for(int num:nums){
            if(count==0){
                ans=num;
                count++;
            }else{
                if(num==ans)
                    count++;
                else
                    count--;
            }
        }
        return ans;
    }
};