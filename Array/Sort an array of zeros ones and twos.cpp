//Time: O(n)
//Space: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left=-1;
        int right=nums.size();
        for(int i=0;i<right;i++){
            if(nums[i]==0){
                swap(nums[++left],nums[i]);
            }
            if(nums[i]==2){
                swap(nums[--right],nums[i--]);
            }
        }
    }
};