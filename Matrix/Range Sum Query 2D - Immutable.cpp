//Time: O(1)per query, O(m*n) for pre-computation
//Space: O(m*n)
class NumMatrix {
private:
    vector<vector<int>> imatrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        imatrix=matrix;
        int m=imatrix.size();
        if(m!=0){
            int n=imatrix[0].size();
            for(int i=1;i<m;i++)
                imatrix[i][0]+=imatrix[i-1][0];
            for(int j=1;j<n;j++)
                imatrix[0][j]+=imatrix[0][j-1];
            for(int i=1;i<m;i++){
                for(int j=1;j<n;j++){
                    imatrix[i][j]+=imatrix[i-1][j]+imatrix[i][j-1]-imatrix[i-1][j-1];
                }
            } 
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=imatrix[row2][col2];
        if(row1-1>=0)
            ans-=imatrix[row1-1][col2];
        if(col1-1>=0)
            ans-=imatrix[row2][col1-1];
        if(col1-1>=0 && row1-1>=0)
            ans+=imatrix[row1-1][col1-1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */