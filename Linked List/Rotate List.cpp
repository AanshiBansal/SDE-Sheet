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

//Time: O(n)
//Space: O(1)
class Solution {
private:
    int countNodes(ListNode* head){
        int ans=0;
        while(head){
            ans++;
            head=head->next;
        }
        return ans;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return head;
        int length=countNodes(head);
        k%=length;
        if(k==0)
            return head;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=new ListNode();
        while(k){
            fast=fast->next;
            k--;
        }
        while(fast){
            prev=slow;
            fast=fast->next;
            slow=slow->next;
        }
        prev->next=NULL;
        ListNode*ans=slow;
        while(slow->next){
            slow=slow->next;
        }
        slow->next=head;
        return ans;
    }
};