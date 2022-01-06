//Time: O(m*n)
//Space: O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(m==0)
            return;
        int n=matrix[0].size();
        if(n==0)
            return;
        //Saving ans for column 0
        int col_0=1;
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0){
                col_0=0;
                break;
            }
        }
        //Saving ans for all rows in first cell of the row
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    break;
                }
            }
        }
        //Saving ans for all columns in first cell of the column except column 0
        for(int j=1;j<n;j++){
            for(int i=0;i<m;i++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    break;
                }
            }
        }
        //Applying ans to all columns except column 0
        for(int j=1;j<n;j++){
            if(matrix[0][j]==0){
                for(int i=1;i<m;i++){
                    matrix[i][j]=0;
                }
            }
        }
        //Applying answer to all rows
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0){
                for(int j=1;j<n;j++){
                    matrix[i][j]=0;
                }
            }
        }
        //Applying ans to column 0
        if(col_0==0){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
        return;
    }
};