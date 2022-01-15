//Time: O(log(n))
//Space: O(log(n))
class Solution {
public:
    double myPow(double x, int n) {
        if(n==INT_MIN)
            return 1/(myPow(x,INT_MAX)*x);
        if(n<0)
            return 1/myPow(x,-1*n);
        if(n==0)
            return 1;
        bool odd=n%2;
        double ans=myPow(x,n/2);
        double sol=ans*ans;
        if(odd)
            sol*=x;
        return sol;
    }
};