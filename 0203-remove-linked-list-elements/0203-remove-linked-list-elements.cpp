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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
//         ListNode*temp=head;
//         // ListNode*ptr=temp->next;
// while(temp!=NULL){
//     if(curr->val==val){
//         temp->next=curr->next;
//         curr=temp->next;
//     }
//     else{
//         temp=curr;
//         curr=curr->next;
//     }
// }
// return head;

if (head == NULL) return head;  
        while (head != NULL && head->val == val) {
            head = head->next;
        }
        if (head == NULL) return head;
        ListNode* temp = head;
        ListNode* curr = temp->next;

        while (temp != NULL && curr != NULL) {
            if (curr->val == val) {
                temp->next = curr->next;  
                curr = temp->next;        
            } else {
                temp = curr;             
                curr = curr->next;
            }
        }
        return head;
    }
};