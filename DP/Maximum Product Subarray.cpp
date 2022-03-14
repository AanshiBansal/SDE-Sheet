// https://leetcode.com/problems/maximum-product-subarray/
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mini = nums[0];
        int maxi = nums[0];
        int result = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(mini,maxi);
            }
            mini=min(nums[i],mini*nums[i]);
            maxi=max(nums[i],maxi*nums[i]);
            result=max(result,maxi);
        }
        return result;
    }
};