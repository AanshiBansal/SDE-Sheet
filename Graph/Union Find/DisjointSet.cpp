class disjointSet{
    private:
        vector<int>parent;
        vector<int>rank;
    public:
        disjointSet(int n){
            parent=vector<int>(n);
            rank=vector<int>(n,0);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        void unionSet(int a, int b){
            int rootA=find(a);
            int rootB=find(b);
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
        int find(int x){
            if(parent[x]==x)
                return x;
            return parent[x]=find(parent[x]);;
        }
};