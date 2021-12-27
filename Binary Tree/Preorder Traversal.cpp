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
    void preorderRecursive(TreeNode* root, vector<int>&preorder){
        if(root==NULL)
            return;
        preorder.push_back(root->val);
        preorderRecursive(root->left,preorder);
        preorderRecursive(root->right,preorder);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>preorder;
        preorderRecursive(root, preorder);
        return preorder;
    }
};

//Iterative Using Stack
//Space: O(n)
//Time: O(n)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>preorder;
        stack<TreeNode*>s;
        TreeNode*curr=root;
        while(curr!=NULL || !s.empty()){
            if(curr!=NULL){
                preorder.push_back(curr->val);
                s.push(curr);
                curr=curr->left;
            }else{
                curr=s.top()->right;
                s.pop();
            }
        }
        return preorder;
    }
};

//Morris Traversal
//Space: O(1)
//Time: O(n)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>preorder;
        TreeNode*curr=root;
        TreeNode*prev;
        while(curr!=NULL){
            if(curr->left==NULL){
                preorder.push_back(curr->val);
                curr=curr->right;
            }else{
                prev=curr->left;
                while(prev->right!=NULL && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    preorder.push_back(curr->val);
                    prev->right=curr;
                    curr=curr->left;
                }else{
                    prev->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return preorder;
    }
};