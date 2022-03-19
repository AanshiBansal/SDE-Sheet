//Problem: https://leetcode.com/problems/binary-tree-inorder-traversal/
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
 
//Recursive
//Space: Auxillary Array O(n)
//Time: O(n)
class Solution {
public:
    void inorderRecursive(TreeNode* root, vector<int>&inorder){
        if(root==NULL)
            return;
        inorderRecursive(root->left,inorder);
        inorder.push_back(root->val);
        inorderRecursive(root->right,inorder);
        return;
    }

    vector<int> inorderTraversal(TreeNode* root){
        vector<int>inorder;
        inorderRecursive(root, inorder);
        return inorder;
    }
};

//Iterative Using Stack
//Space: O(n)
//Time: O(n) 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>s;
        vector<int>ans;
        while(root!=NULL || !s.empty()){
            if(root!=NULL){
                s.push(root);
                root=root->left;
            }else{
                ans.push_back(s.top()->val);
                root=s.top()->right;
                s.pop();
            }
        }
        return ans;
    }
};

//Morris Traversal
//Space: O(1)
//Time: O(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        TreeNode* curr=root;
        TreeNode* prev;
        while(curr){
           if(curr->left==NULL){
               inorder.push_back(curr->val);
               curr=curr->right;
           }else{
               prev=curr->left;
               while(prev->right!=NULL && prev->right!=curr){
                   prev=prev->right;
               }
               if(prev->right==NULL){
                   prev->right=curr;
                   curr=curr->left;
               }else{
                   prev->right=NULL;
                   inorder.push_back(curr->val);
                   curr=curr->right;
               }
           }
        }
        return inorder;
    }
};