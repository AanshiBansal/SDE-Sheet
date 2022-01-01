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
 
Time: O(length of list)
Space: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* ans=new ListNode();
        ListNode* prev=ans;
        prev->next=head;
        while(n--){
            fast=fast->next;
        };
        while(fast){
            prev=slow;
            fast=fast->next;
            slow=slow->next;
        }
        prev->next=slow->next;
        return ans->next;
    }
};