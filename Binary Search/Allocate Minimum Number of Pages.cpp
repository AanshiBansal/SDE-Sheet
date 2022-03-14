int Solution::books(vector<int> &A, int B) {
    int low=0;
    int high=0;
    int n=A.size();
    if(n<B)
        return -1;
    for(int i=0;i<n;i++){
        low=max(low,A[i]);
        high+=A[i];
    }
    while(low<high){
        int mid=(low+high)/2;
        int p=1;
        int curr=0;
        for(int i=0;i<n;i++){
            if(curr+A[i]<=mid){
                curr+=A[i];
            }else{
                curr=A[i];
                p++;
            }
        }
        if(p>B){
            low=mid+1;
        }else{
            high=mid;
        }
    }
    return low;

}