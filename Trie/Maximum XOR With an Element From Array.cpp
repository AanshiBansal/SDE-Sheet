struct TrieNode{
    vector<TrieNode*>links;
    TrieNode(){
        links=*new vector<TrieNode*>(2,NULL);
    };
};

class Trie{
    private:
        TrieNode* root;
    public:
        Trie(){
            root=new TrieNode();
        };
        void insert(int num){
            TrieNode* curr=root;
            for(int i=31;i>=0;i--){
                int bit=(num>>i)&1;
                if(curr->links[bit]==NULL)
                    curr->links[bit]= new TrieNode();
                curr=curr->links[bit];
            }
        };
        int findMax(int num){
            int maxNum=0;
            TrieNode* curr=root;
            for(int i=31;i>=0;i--){
                int bit=(num>>i)&1;
                bit=1-bit;
                if(curr->links[bit]!=NULL){
                    maxNum|=(1<<i);
                    curr=curr->links[bit];
                }else{
                    bit=1-bit;
                    curr=curr->links[bit];
                }
            }
            return maxNum;
        };
    
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int q=queries.size();
        vector<vector<int>>offlineQueries;
        vector<int>ans(q);
        for(int i=0;i<q;i++){
            offlineQueries.push_back({queries[i][1],queries[i][0],i});
        }
        sort(offlineQueries.begin(),offlineQueries.end());
        int index=0;
        Trie trie;
        for(int i=0;i<q;i++){
            while(index<n && nums[index]<=offlineQueries[i][0]){
                trie.insert(nums[index]);
                index++;
            }
            if(index==0)
                ans[offlineQueries[i][2]]=-1;
            else
                ans[offlineQueries[i][2]]=trie.findMax(offlineQueries[i][1]);
        }
        return ans;
    }
};