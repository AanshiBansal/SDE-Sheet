// Union Find/ Disjoint Set works only on undirected graph
//Base Version
// Time: find and union function takes O(n) is worst case
// The trees created to represent subsets can be skewed and can become like a linked list.
class Solution {
private:
    int find(vector<int>&parent, int x){
        while(parent[x]!=x){
            x=parent[x];
        }
        return x;
    }
    void unionSet(vector<int>&parent, int a, int b){
        int rootA=find(parent,a);
        int rootB=find(parent,b);
        parent[rootA]=rootB;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>parent(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j])
                    unionSet(parent,i,j);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i)
                ans++;
        }
        return ans;
    }
};

//Union By Rank

//Time: O(log(n))
// Since it is the depth of the tree that affects the running time,
// the tree with a smaller depth gets added under the root of the deeper tree, 
// which only increases the depth of the depths were equal. 
// Single element trees are defined to have a rank of zero,
// and whenever two trees of the same rank r are united, the result has the rank of r+1.

void unionSet(vector<int>&parent, vector<int>&rank, int a, int b){
    int rootA=find(parent,a);
    int rootB=find(parent,b);
    if(rank[rootA]<rank[rootB]){
        parent[rootA]=rootB;
    }
    if(rank[rootB]<rank[rootA]){
        parent[rootB]=rootA;
    }
    if(rank[rootB]==rank[rootA]){
        parent[rootA]=rootB;
        rank[rootB]++;
    }
}

//Path Compression

// Find recursively traverses up the tree,
// it changes each node’s parent reference to point to the root that is found.
// The resulting tree is much flatter,
// speeding up future operations not only on these elements but on those referencing them, directly or indirectly.
int find(vector<int>&parent, int x){
    if(parent[x]==x)
        return x;
    parent[x]=find(parent, parent[x]);
    return parent[x];
}

// https://www.techiedelight.com/disjoint-set-data-structure-union-find-algorithm/
