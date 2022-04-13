// https://leetcode.com/problems/3sum-smaller/

// Binary Search Approach
//Time: O(n^2*log(n))
//Space: O(n) Auxiliary Array because of sorting
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int n=nums.size();
        for(int i=0;i<=n-3;i++){
            for(int j=i+1;j<=n-2;j++){
                int low=j+1;
                int high=n-1;
                while(low<=high){
                    int mid=(low+high)/2;
                    if(nums[i]+nums[j]+nums[mid]<target){
                        low=mid+1;
                    }else{
                        high=mid-1;
                    }
                }
                ans+=(low-j-1);
            }
        }
        return ans;
    }
};

//2-Pointer Approach
//Time: O(n^2)
//Space: O(n) Auxiliary Array because of sorting
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int n=nums.size();
        for(int i=0;i<=n-3;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]>=target){
                    k--;
                }else{
                    ans+=(k-j);
                    j++;
                }
            }
        }
        return ans;
    }
};
