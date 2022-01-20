//Time: O(n*log(n))
//Space: O(n) because of temporary array used while merging and log(n) recursive calls
#include<vector>
void merge(long long *arr,int start, int mid, int end){
    vector<long long>temp;
    int i=start;
    int j=mid+1;
    while(i<=mid && j<=end){
        if(arr[i]<arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=end){
        temp.push_back(arr[j++]);
    }
    for(int i=0;i<temp.size();i++){
        arr[i+start]=temp[i];
    }
}
long long customFn(long long *arr, int start, int mid, int end){
    int i=start;
    int j=mid+1;
    long long ans=0;
    while(i<=mid){
        while(j<=end && arr[j]<arr[i]){
            j++;
        }
        ans+=j-(mid+1);
        i++;
    }
    return ans;
}
long long mergeSort(long long *arr, int start, int end){
    if(start>=end)
        return 0;
    int mid=(start+end)/2;
    long long first=mergeSort(arr,start,mid);
    long long second=mergeSort(arr,mid+1,end);
    long long curr=customFn(arr,start,mid,end);
    merge(arr,start,mid,end);
    return first+second+curr;
}
long long getInversions(long long *arr, int n){
    return mergeSort(arr,0,n-1);
}