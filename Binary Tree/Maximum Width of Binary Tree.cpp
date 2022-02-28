// Time: O(n)
// Space: O(n)
// Concept from Heap data structure: Node index mapping
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        long long ans=1;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            long long start=q.front().second;
            long long end=q.back().second;
            ans=max(ans,end-start+1);
            for(int i=0;i<size;i++){
                pair<TreeNode*,long long>front=q.front();
                q.pop();
                if(front.first->left)
                    q.push({front.first->left,2*(front.second-start)});
                if(front.first->right)
                    q.push({front.first->right,2*(front.second-start)+1});
            }
        }
        return ans;
    }
};