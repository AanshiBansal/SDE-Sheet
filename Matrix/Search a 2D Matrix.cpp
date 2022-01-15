//Time: O(m+n)
//Space: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if(m==0)
            return false;
        int n=matrix[0].size();
        if(n==0)
            return false;
        int i=0;
        int j=n-1;
        while(i<m && j>=0){
            if(matrix[i][j]==target)
                return true;
            if(matrix[i][j]<target){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
};

//Time: O(log(m*n))
//Space: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if(m==0)
            return false;
        int n=matrix[0].size();
        if(n==0)
            return false;
        int i=0;
        int j=m*n-1;
        while(i<=j){
            int mid=(i+j)/2;
            int x=mid/n;
            int y=mid%n;
            if(matrix[x][y]==target)
                return true;
            if(matrix[x][y]<target)
                i=mid+1;
            else
                j=mid-1;
        }
        return false;
    }
};