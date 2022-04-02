// DFS Backtracking
// Time: O(m*n*(3^k)) where is length of word
// Space: O(k)
// Amazon

class Solution {
private:
    bool dfs(vector<vector<char>>& board, string &word, int index, int i, int j, int m, int n){
        if(index==word.size())
            return true;
        if(i<0 || i==m || j<0 || j== n || board[i][j]!=word[index])
            return false;
        char c=board[i][j];
        board[i][j]='*';
        bool top=dfs(board,word,index+1,i-1,j,m,n);
        bool bottom=dfs(board,word,index+1,i+1,j,m,n);
        bool left=dfs(board,word,index+1,i,j-1,m,n);
        bool right=dfs(board,word,index+1,i,j+1,m,n);
        board[i][j]=c;
        return top || bottom || left || right;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        if(m==0)
            return false;
        int n=board[0].size();
        if(n==0)
            return false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(board,word,0,i,j,m,n))
                    return true;
            }
        }
        return false;
    }
};