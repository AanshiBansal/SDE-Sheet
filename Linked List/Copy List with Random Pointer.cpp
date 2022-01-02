/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// Time: O(n)
// Space: O(n)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
        Node* ans= new Node(0);
        Node* curr=ans;
        while(head){
            curr->next= new Node(head->val);
            curr=curr->next;
            mp[head]=curr;
            head=head->next;
        }
        for(auto nodes: mp){
            if(nodes.first->random)
                nodes.second->random=mp[nodes.first->random];
        }
        return ans->next;
    }
};

// Time: O(n)
// Space: O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        //Inserting new nodes in between old list
        Node* curr=head;
        while(curr){
            Node* temp=new Node(curr->val);
            temp->next=curr->next;
            curr->next=temp;
            curr=curr->next->next;
        }
        //Pointing random
        curr=head;
        while(curr){
            if(curr->random)
                curr->next->random=curr->random->next;
            curr=curr->next->next;
        }
        //Separating both the lists
        Node* ans=new Node(0);
        Node* currAns=ans;
        curr=head;
        while(curr){
            currAns->next=curr->next;
            curr->next=curr->next->next;
            currAns=currAns->next;
            curr=curr->next;
        }
        return ans->next;
    }
};