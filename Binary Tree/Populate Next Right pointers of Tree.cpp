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

void connect(TreeLinkNode *root) {
    if(root == NULL)
        return;
        
    if(root->left != NULL) root->left->next = root->right;
    if(root->right != NULL && root->next != NULL) root->right->next = root->next->left;

    
    connect(root->left);
    connect(root->right);
}