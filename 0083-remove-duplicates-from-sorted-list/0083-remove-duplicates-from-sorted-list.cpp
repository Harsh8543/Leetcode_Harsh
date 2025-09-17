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
// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         ListNode*temp=head;
//         ListNode*curr=temp->next;
//         while(temp!=NULL && curr!=NULL){
//             if(temp->val==curr->val){
//                 temp->next=curr->next;
//                 curr=temp->next;
//             }
//           else {
//                 temp = curr;               
//                 curr = curr->next;        
//             }
//         }
//         return head;
//     }
// };
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;   

        ListNode* temp = head;
        ListNode* curr = temp->next;

        while (temp != NULL && curr != NULL) {
            if (temp->val == curr->val) {
                temp->next = curr->next;
                curr = temp->next;
            }
            else {
                temp = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
