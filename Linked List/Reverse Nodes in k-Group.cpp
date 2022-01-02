/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 
//Recursive
//Time: O(n)
//Space: O(n/k)<O(n)
class Solution {
private:
    bool reverseList(ListNode* head, int k){
        while(head && k){
            head=head->next;
            k--;
        }
        return k==0;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)
            return NULL;
        if(!reverseList(head,k))
            return head;
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*next;
        int count=k;
        while(curr && count){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count--;
        }
        head->next=reverseKGroup(curr,k);
        return prev;
    }
};

//Iterative
//Time: O(n)
//Space: O(1)
class Solution {
private:
    bool reverseList(ListNode* head, int k){
        while(head && k){
            head=head->next;
            k--;
        }
        return k==0;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ans=new ListNode();
        ListNode* currEnd=ans;
        while(head){
            if(!reverseList(head,k)){
                currEnd->next=head;
                break;
            }
            ListNode*curr=head;
            ListNode*prev=NULL;
            ListNode*next;
            int count=k;
            while(curr && count){
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
                count--;
            }
            currEnd->next=prev;
            currEnd=head;
            head=curr;
        }
        return ans->next;
    }
};