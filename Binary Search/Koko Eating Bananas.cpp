//Time: O(n*log(m)) where m is the maximum number of bananas in a single pile from piles
//Space: O(1)
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if(piles.size()==0)
            return 0;
        int mini=1;
        int maxi=piles[0];
        for(int i=1;i<piles.size();i++)
            maxi=max(maxi,piles[i]);
        while(mini<maxi){
            int mid=(mini+maxi)/2;
            int hours=0;
            for(int i=0;i<piles.size();i++){
                hours+=piles[i]/mid;
                if(piles[i]%mid!=0)
                    hours++;
            }
            if(hours>h){
                mini=mid+1;
            }else{
                maxi=mid;
            }
        }
        return mini;
    }
};