// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/

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
private:
    bool pathFn(TreeNode* root, string dir, int val, stack<pair<int,string>>&path){
        if(root==NULL)
            return false;
        if(root->val == val){
            path.push({root->val,dir});
            return true;
        }
        bool left=pathFn(root->left,"L",val,path);
        bool right=pathFn(root->right,"R",val,path);
        if(left || right){
            path.push({root->val,dir});
            return true;
        }
        return false;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        stack<pair<int,string>>startPath;
        stack<pair<int,string>>destPath;
        pathFn(root,"Root",startValue,startPath);
        pathFn(root,"Root",destValue,destPath);
        string ans="";
        while(!startPath.empty() && ! destPath.empty() && startPath.top()==destPath.top()){
            startPath.pop();
            destPath.pop();
        }
        for(int i=0;i<startPath.size();i++)
            ans+="U";
        while(!destPath.empty()){
            ans+=destPath.top().second;
            destPath.pop();
        }
        return ans;
    }
};