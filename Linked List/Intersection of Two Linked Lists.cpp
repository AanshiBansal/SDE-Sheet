/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//Time: o(m+n)
//Space: O(min(m,n))
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*>s;
        while(headA){
            s.insert(headA);
            headA=headA->next;
        }
        while(headB){
            if(s.find(headB)!=s.end())
                return headB;
            headB=headB->next;
        }
        return NULL;
    }
};

//Time: o(m+n)
//Space: O(1)
class Solution {
private:
    int lengthLinkedList(ListNode *head){
        int ans=0;
        while(head){
            ans++;
            head=head->next;
        };
        return ans;
    };
    ListNode* reduceLinkedList(ListNode* head, int n){
        while(head && n>0){
            head=head->next;
            n--;
        };
        return head;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA=lengthLinkedList(headA);
        int lengthB=lengthLinkedList(headB);
        headA=reduceLinkedList(headA, max(lengthA-lengthB,0));
        headB=reduceLinkedList(headB, max(lengthB-lengthA,0));
        while(headA && headB){
            if(headA==headB)
                return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};