//Time Complexity: O(max(Number of trips, Number of locations))
//Space Complexity: O(Number of locations)
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>location(1001,0);
        for(int i=0;i<trips.size();i++){
            //Add passengers at the starting location
            location[trips[i][1]]+=trips[i][0];
            //Remove passengers at the ending location
            location[trips[i][2]]-=trips[i][0];
        }
        if(location[0]>capacity)
            return false;
        for(int i=1;i<1001;i++){
            //Calculate passengers at each location
            location[i]+=location[i-1];
            if(location[i]>capacity)
                return false;
        }
        return true;
    }
};