//Hash Map
//Time: O(n)
//Space: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])==mp.end()){
                mp[nums[i]]=i;
            }else{
                return {mp[target-nums[i]],i};
            }
        }
        return {};
    }
};

//2 Pointer Approach
//Time: O(n*log(n)) Requires sorting
//Space: O(1) but O(n) if stored in new array and also to preserve indexes if those have to be returned
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>sortedNums(n,vector<int>(2));
        for(int i=0;i<n;i++){
            sortedNums[i][0]=nums[i];
            sortedNums[i][1]=i;
        }
        sort(sortedNums.begin(),sortedNums.end());
        int i=0;
        int j=n-1;
        while(i<j){
            int sum=sortedNums[i][0]+sortedNums[j][0];
            if(sum==target)
                return {sortedNums[i][1],sortedNums[j][1]};
            if(sum<target)
                i++;
            else
                j--;
        }
        return {};
    }
};