/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
bool customSort(Job A, Job B){
    if(A.profit>B.profit)
        return true;
    if(A.profit<B.profit)
        return false;
    if(A.dead<A.dead)
        return true;
    return false;
}
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int jobs=0;
        int profit=0;
        vector<bool>dead(101,true);
        sort(arr,arr+n,customSort);
        for(int i=0;i<n;i++){
            //cout<<"id "<<arr[i].id<<endl;
            for(int j=arr[i].dead;j>0;j--){
                if(dead[j]){
                    //cout<<j<<endl;
                    dead[j]=false;
                    jobs++;
                    profit+=arr[i].profit;
                    break;
                }
            }
        }
        return {jobs,profit};
    } 
};

// Using Union Find/ Disjoint set
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
        // your code here
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