/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        priority_queue<pair<double,int>>pq;
        for(int i=0;i<n;i++){
            pq.push({double(arr[i].value)/arr[i].weight,i});
        }
        double ans=0.0;
        while(W>0 && !pq.empty()){
            int index=pq.top().second;
            pq.pop();
            if(arr[index].weight<=W){
                W-=arr[index].weight;
                ans+=arr[index].value;
            }else{
                ans+=(double(arr[index].value)/arr[index].weight)*W;
                W=0;
            }
        }
        return ans;
    }
        
};