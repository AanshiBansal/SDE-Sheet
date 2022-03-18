int help(vector<int>&A, int num){
    int low=0;
    int high=A.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(A[mid]<=num){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return low;
}

int Solution::findMedian(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    int target=(n*m)/2 + 1;
    int low=1;
    int high=1000000000;
    while(low<=high){
        int mid=(low+high)/2;
        int count=0;
        for(int i=0;i<n;i++){
            count+=help(A[i],mid);
        }
        if(count<target){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return low;
}
