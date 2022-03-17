bool customSort(pair<int,int>A,pair<int,int>B){
    return A.second<B.second;
}
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>v(n);
        int ans=0;
        for(int i=0;i<n;i++){
            v[i]={start[i],end[i]};
        }
        sort(v.begin(),v.end(),customSort);
        int ends=-1;
        for(int i=0;i<n;i++){
            if(v[i].first>ends){
                ans++;
                ends=v[i].second;
            }
        }
        return ans;
    }
};