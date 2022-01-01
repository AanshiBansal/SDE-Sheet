Given a positive integer k,
you need to find the length of the smallest positive integer n
such that n is divisible by k, and n only contains the digit 1.

Return the length of n. If there is no such n, return -1.

Note: n may not fit in a 64-bit signed integer.

Input: k = 3
Output: 3
Explanation: The smallest answer is n = 111, which has length 3.

N(l)=q*k+r;
N(l+1)=10*N(l)+1;
N(l+1)=10*(q*k+r)+1;
N(l+1)%k=((10*r)+1)%k because (10*q*k)%k=0

Maximum possible remainders are k from 0 to k-1, hence if 0 does not appear in k times it wont ever come

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k==1)
            return 1;
        int remainder=1;
        for(int i=2;i<=k;i++){
            remainder=(10*remainder+1)%k;
            if(remainder==0)
                return i;
        }
        return -1;
    }
};