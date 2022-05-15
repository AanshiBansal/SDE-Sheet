// Print all the paths in the binary tree which constitutes to a given average value. 
// The path does not need to start or end at the root or a leaf
// but it must go downwards (i.e., traveling only from parent nodes to child nodes).

// Amazon
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
}

void inorder(TreeNode* root, vector<int>&path, vector<vector<int>>&ans, double &average){
    path.push_back(root->val);
    int size=path.size();
    for(int i=0;i<size;i++){
        double sum=0;
        for(int j=i;j<size;j++){
            sum+=path[j];
        }
        int count=(size-i);
        if(sum/count==average){
            vector<int>temp;
            for(int k=i;k<=j;k++){
                temp.push_back(path[k]);
            }
            ans.push_back(temp);
        }
    }
    if(root->left !=NULL)
        inorder(root->left, path, ans, average);
    if(root->right !=NULL)
        inorder(root->right,path,ans, average);
    path.pop_back();
}

vector<vector<int>> pathsWithAvgVal(TreeNode* root, double average){
    vector<vector<int>>ans;
    vector<int>path;
    if(root==NULL)
        return ans;
    inorder(root,path,ans,average);
    return ans;
}