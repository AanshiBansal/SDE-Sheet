//Time: O(n*log(n))
//Space: O(n) Auxiliary Array for sorting
bool customSort(vector<int>&A, vector<int>&B){
    return A[1]<B[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),customSort);
        int ans=0;
        long long last=LLONG_MIN;
        for(int i=0;i<points.size();i++){
            if(points[i][0]>last){
                ans++;
                last=points[i][1];
            }
        }
        return ans;
    }
};