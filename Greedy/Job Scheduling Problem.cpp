/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
bool customSort(Job A, Job B){
    return A.profit>B.profit;
}
int find(vector<int> &parent, int a){
    if(parent[a]==a)
        return a;
    parent[a]=find(parent,parent[a]);
    return parent[a];
}
bool unionSet(vector<int>&parent, int a, int b){
    int rootA=find(parent,a);
    int rootB=find(parent,b);
    parent[rootA]=rootB;
}
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int jobs=0;
        int profit=0;
        vector<int>parent(101);
        for(int i=0;i<=100;i++)
            parent[i]=i;
        sort(arr,arr+n,customSort);
        for(int i=0;i<n;i++){
            int d=find(parent,arr[i].dead);
            if(d!=0){
                jobs++;
                profit+=arr[i].profit;
                unionSet(parent,d,d-1);
            }
            
        }
        return {jobs,profit};
    } 
};