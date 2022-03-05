// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* right=root->right;
        root->right=root->left;
        root->left=NULL;
        TreeNode* temp=root;
        while(temp->right){
            temp=temp->right;
        }
        temp->right=right;
        return;
    }
};

// More elegant solution
class Solution {
    TreeNode* prev=NULL;
public:
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        flatten(root->right);
        flatten(root->left);
        TreeNode* right=root->right;
        root->right=prev;
        root->left=NULL;
        prev=root;
        return;
    }
};