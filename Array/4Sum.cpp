//Time: O(n^3)
//Space: O(n) because of sorting
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(i-1>=0 && nums[i-1]==nums[i])
                continue;
            for(int j=i+1;j<n;j++){
                if(j-1!=i && nums[j]==nums[j-1])
                    continue;
                int req=target-nums[i]-nums[j];
                int k=j+1;
                int l=n-1;
                while(k<l){
                    if(nums[k]+nums[l]==req){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;l--;
                        while(k<n && nums[k]==nums[k-1]){
                            k++;
                        }
                        while(l>=0 && nums[l]==nums[l+1]){
                            l--;
                        }
                    }else{
                        if(nums[k]+nums[l]<req){
                            k++;
                            while(k<n && nums[k]==nums[k-1]){
                                k++;
                            }
                        }else{
                            l--;
                            while(l>=0 && nums[l]==nums[l+1]){
                                l--;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};