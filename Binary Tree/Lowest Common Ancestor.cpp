// Recursive
// Time: O(n)
// Space: O(n): skewed
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int helper(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans){
        if(root == NULL)
            return 0;
        int curr = (root==p || root ==q)?1:0;
        int left = helper(root->left,p,q,ans);
        int right = helper(root->right,p,q,ans);
        if(left==2 || right==2)
            return 2;
        if(curr+left+right == 2){
            ans=root;
        }
        return curr+left+right;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=NULL;
        helper(root,p,q,ans);
        return ans;
    }
};

// Clean solution but assums that both nodes are part of tree
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left==NULL)
            return right;
        if(right==NULL)
            return left;
        return root;
    }
};