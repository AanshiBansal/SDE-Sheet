/*struct Node{
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

//Time: O(m*n*n) == O(1*m + 2*m + 3*m + .... + (n-1)*m) where m is the average length of sub-linked-lists
//Space: O(n)
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

//Time: O(m*n*n)
//Space: O(1)
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