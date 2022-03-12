// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

// BFS
// Time: O(n)
// Space: O(n)
Node* connect(Node* root) {
	queue<Node*>q;
	if (root==NULL)
		return root;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		Node* front= q.front();
		q.pop();
		if(front==NULL){
			if(!q.empty())
				q.push(NULL);
		}else{
			front->next=q.front();
			if(front->left)
				q.push(front->left);
			if(front->right)
				q.push(front->right);
		}
	}
	return root;
}

// BFS
// Time: O(n)
// Space: O(1)
void connect(TreeLinkNode *root) {
	TreeLinkNode* level_start = root;
	
	while(level_start!=NULL)
	{
		//curr is the first node in that level
		TreeLinkNode* curr = level_start;
		
		//Keep going to the right in that level
		while(curr!=NULL)
		{
			if(curr->left!=NULL) curr->left->next=curr->right;
			if(curr->right!=NULL && curr->next!=NULL) curr->right->next=curr->next->left;
			
			curr = curr->next;
		}
		level_start=level_start->left;
	}
	
}

// DFS
// Time: O(n)
// Space: O(h)
void connect(TreeLinkNode *root) {
    if(root == NULL)
        return;
        
    if(root->left != NULL) root->left->next = root->right;
    if(root->right != NULL && root->next != NULL) root->right->next = root->next->left;

    connect(root->left);
    connect(root->right);
}