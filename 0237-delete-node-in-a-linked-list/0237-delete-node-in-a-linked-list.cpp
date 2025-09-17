/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
      if (node == NULL || node->next == NULL) return; 

        ListNode* temp = node;          
        ListNode* curr = temp->next;   
        temp->val = curr->val;          
        temp->next = curr->next;  
    }
};