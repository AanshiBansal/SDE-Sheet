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
 
//Time O(n)
//Space O(n)
//Using Level Order Traversal using queue
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>rightView;
        if(root==NULL)
            return rightView;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int prev;
        TreeNode* curr;
        while(!q.empty()){
            curr=q.front();
            q.pop();
            if(curr==NULL){
                rightView.push_back(prev);
                if(!q.empty())
                    q.push(NULL);
            }else{
                prev=curr->val;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
        return rightView;
    }
};