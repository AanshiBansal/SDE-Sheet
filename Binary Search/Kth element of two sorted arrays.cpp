// https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1#

class Solution{
    public:
    int kthElement(int nums1[], int nums2[], int n, int m, int k)
    {
        if(n>m)
            return kthElement(nums2,nums1,m,n,k);
        
        int low=max(0,k-m-1);
        int high=min(k-1,n-1);
        while(low<=high){
            int mid=(low+high)/2;
            int s1=mid+1;
            int s2=k-s1;
            int l1=s1-1>=0 ? nums1[s1-1] : INT_MIN;
            int l2=s2-1>=0 ? nums2[s2-1] : INT_MIN;
            int r1=s1 < n ? nums1[s1] : INT_MAX;
            int r2=s2 < m ? nums2[s2] : INT_MAX;
            if(l1<=r2 && l2<=r1){
                return max(l1,l2);
            }
            if(l1>r2){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return nums2[k-1];
    }
};