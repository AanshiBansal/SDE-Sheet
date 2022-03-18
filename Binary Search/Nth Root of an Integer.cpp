// Time: O(log(n)*log(M*10^d))

double power(double m, int n){
    if(n==1)
        return m;
    double r=power(m,n/2);
    if(n%2==0)
        return r*r;
    return r*r*m;
}
double findNthRootOfM(int n, long long m) {
	// Write your code here.
    double epsilon=1e-7;
    double low=1.0;
    double high=m;
    while((high-low)>epsilon){
        double mid=(low+high)/2.0;
        double r=power(mid,n);
        if(r>m){
            high=mid;
        }else{
            low=mid;
        }
    }
    return low;
}
