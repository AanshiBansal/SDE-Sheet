/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Time O(n)
//Space O(n)
//Using Level Order Traversal using queue
vector<int> leftView(Node *root)
{
   vector<int>leftView;
    if(root==NULL)
        return leftView;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    bool prevNull=true;
    Node* curr;
    while(!q.empty()){
        curr=q.front();
        q.pop();
        if(curr==NULL){
            prevNull=true;
            if(!q.empty())
                q.push(NULL);
        }else{
            if(prevNull){
                leftView.push_back(curr->data);
                prevNull=false;
            }
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
    }
    return leftView;
}