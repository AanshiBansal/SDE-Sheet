struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

//Time O(m*n)

Node* merge(Node* first, Node* second){
    Node* ans=new Node(0);
    Node* curr=ans;
    while(first && second){
        if(first->data<second->data){
            curr->bottom=first;
            first=first->bottom;
        }else{
            curr->bottom=second;
            second=second->bottom;
        }
        curr=curr->bottom;
    };
    if(first)
        curr->bottom=first;
    else
        curr->bottom=second;
    return ans->bottom;
}
Node *flatten(Node *root)
{
    if(root==NULL)
        return NULL;
    Node* first=root;
    Node* second=flatten(root->next);
    root->next=NULL;
    root=merge(first,second);
    return root;
}

Node *flatten(Node *root)
{
    Node* curr=root;
    Node* next;
    Node* ans=NULL;
    while(curr){
        ans=merge(curr,ans);
        next=curr->next;
        curr->next=NULL;
        curr=next;
    }
    return ans;
}