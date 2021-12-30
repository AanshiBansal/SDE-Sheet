//Time: O(n) if sorted else O(n*log(n))
//Space: O(1) if sorted else auxiliary array
class Solution{   
public:
    long long findSmallest(long long arr[], int n) {
        long long ans=1;
        for(int i=0;i<n;i++){
            if(ans<arr[i])
                return ans;
            ans+=arr[i];
        }
        return ans;
    }
};