class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	vector<int>p(2401,0);
    	for(int i=0;i<n;i++){
    	    p[arr[i]]++;
    	    p[dep[i]+1]--;
    	}
    	int ans=p[0];
    	for(int i=1;i<=2400;i++){
    	    p[i]+=p[i-1];
    	    ans=max(ans,p[i]);
    	}
    	return ans;
    }
};