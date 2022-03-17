bool isSafe(int c, int node, vector<int>&color, bool graph[101][101], int V){
    for(int i=0;i<V;i++){
        if(graph[node][i] && color[i]==c)
            return false;
    }
    return true;
}
bool recursive(int node, int m, vector<int>&color, int V, bool graph[101][101]){
    if(node==V)
        return true;
    for(int i=1;i<=m;i++){
        if(isSafe(i,node,color,graph,V)){
            color[node]=i;
            if(recursive(node+1,m,color,V,graph))
                return true;
            color[node]=0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<int>color(V,0);
    return recursive(0,m,color,V,graph);
}