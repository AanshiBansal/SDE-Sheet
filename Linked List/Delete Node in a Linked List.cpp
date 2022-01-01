/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

Time: O(1)
Space: O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        *node=*node->next;
    }
};