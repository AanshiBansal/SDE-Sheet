//Recursive
//Time: O(log(n)) if balanced else O(n)
//Space: O(log(n)) if balanced else O(n)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL || root->val==val)
            return root;
        if(root->val<val)
            return searchBST(root->right,val);
        else
            return searchBST(root->left,val);
    }
};

//Iterative
//Time: O(log(n)) if balanced else O(n)
//Space: O(1)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root){
            if(root->val==val)
                return root;
            if(val<root->val)
                root=root->left;
            else
                root=root->right;
        }
        return NULL;
    }
};