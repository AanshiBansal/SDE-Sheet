//Time: O(n)
//Space: O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int start=0;
        int curr=0;
        int val=0;
        do{
            val+=gas[curr]-cost[curr];
            curr=(curr+1)%n;
            while(start!=curr && val<0){
                start=(start-1+n)%n;
                val+=gas[start]-cost[start];
            }
        }while(start!=curr);
        return val>=0?start:-1;
    }
};