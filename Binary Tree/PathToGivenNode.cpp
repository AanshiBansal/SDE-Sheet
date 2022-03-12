/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 bool pathFn(TreeNode* root, int val, vector<int>&path){
        if(root==NULL)
            return false;
        path.push_back(root->val);
        if(root->val == val)
            return true;
        bool left=pathFn(root->left,val,path);
        bool right=pathFn(root->right,val,path);
        if(left || right)
            return true;
        path.pop_back();
        return false;
    }
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>ans;
    pathFn(A,B,ans);
    return ans;
}
