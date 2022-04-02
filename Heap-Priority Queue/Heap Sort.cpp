https://www.geeksforgeeks.org/heap-sort/
https://www.geeksforgeeks.org/time-complexity-of-building-a-heap/

https://leetcode.com/problems/sort-an-array/

// Time to build Heap: O(n)
// Heapify function: O(log(n))
// Heap Sort Time: O(n*log(n)), Space: O(log(n))
// In place sorting algorithm
// Following implementation is not stable
class Solution {
private:
    void heapify(vector<int>&nums, int parent, int n){
        int left=2*parent+1;
        int right=2*parent+2;
        int largest=parent;
        if(left<n && nums[left]>nums[parent])
            largest=left;
        if(right<n && nums[right]>nums[largest])
            largest=right;
        if(largest!=parent){
            swap(nums[parent],nums[largest]);
            heapify(nums,largest,n);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=n/2-1;i>=0;i--){
            heapify(nums,i,n);
        }
        for(int i=n-1;i>0;i--){
            swap(nums[0],nums[i]);
            heapify(nums,0,i);
        }
        return nums;
    }
};
