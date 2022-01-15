//Time: O(n)
//Space: O(1)
class Solution {
public:
    int myAtoi(string s) {
        int ans=0;
        bool neg=false;
        int i=0;
        while(i<s.size()){
            if(s[i]!=' ')
                break;
            i++;
        }
        if(i<s.size() && (s[i]=='-'||s[i]=='+')){
            if(s[i]=='-')
                neg=true;
            i++;
        }
        while(i<s.size() && s[i]>='0' && s[i]<='9'){
            if(ans>INT_MAX/10){
                if(neg)
                    return INT_MIN;
                else
                    return INT_MAX;
            }
            ans*=10;
            if(neg && ans>INT_MAX-s[i]+'0')
                return INT_MIN;
            if(neg==false && ans>=INT_MAX-s[i]+'0')
                return INT_MAX;
            ans+=s[i]-'0';
            i++;
        }
        if(neg)
            ans*=-1;
        return ans;
    }
};