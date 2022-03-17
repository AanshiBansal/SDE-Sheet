class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size=nums.size();
        for(int i=0;i<size;i++){
            nums[nums[i]%size]+=size;
        }
        int ans;
        for(int i=0;i<size;i++){
            if(nums[i]/size>1)
                ans=i;
            nums[i]%=size;
        }
        return ans;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise=nums[0];
        int hare=nums[0];
        do{
            hare=nums[nums[hare]];
            tortoise=nums[tortoise];
        }while(hare!=tortoise);
        hare=nums[0];
        while(hare!=tortoise){
            hare=nums[hare];
            tortoise=nums[tortoise];
        }
        return tortoise;
    }
};