//BFS
//Can be solved by DFS as well
//Time: O(m*n) Total nodes
//Space: O(m*n) Total nodes
//Space and Time complexity will be same in case of DFS as well
class Solution {
public:
    vector<vector<int>> floodFill (vector<vector<int>>image, int sr, int sc, int newColor){
        int m=image.size();
        if(m==0)
            return image;
        int n=image[0].size();
        if(n==0)
            return image;
        int oldColor=image[sr][sc];
        if(oldColor==newColor)
            return image;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=newColor;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                if(r+dy[i]>=0 && r+dy[i]<m && c+dx[i]>=0 && c+dx[i]<n && image[r+dy[i]][c+dx[i]]==oldColor){
                    image[r+dy[i]][c+dx[i]]=newColor;
                    q.push({r+dy[i],c+dx[i]});
                }
            }
        }
        return image;
    };
};