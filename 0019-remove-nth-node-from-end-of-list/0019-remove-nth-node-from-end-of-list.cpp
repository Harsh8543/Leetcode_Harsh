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
//     int height(ListNode*head){
//         int k=0;
//         ListNode*temp1=head;
//         while(temp1!=NULL){
//             temp1=temp1->next;
//             k++;
//         }
//         return k;
//     }
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//       ListNode* temp=head;
//       int cnt=0;
//         int l=k-n;
//       while(temp!=NULL){
//         temp=temp->next;
//         cnt++;
//         if(cnt==l){
//           temp->next=temp->next->next;
//         }
//       }
//       return head;
//   }
// };

class Solution {
    int height(ListNode* head) {
        int k = 0;
        ListNode* temp1 = head;
        while (temp1 != NULL) {
            temp1 = temp1->next;
            k++;
        }
        return k;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k = height(head);  
        int l = k - n;
        if (l == 0) {
            return head->next;
        }

        ListNode* temp = head;
        int cnt = 0;
        while (temp != NULL) {
            cnt++;
            if (cnt == l) {  
                temp->next = temp->next->next; 
                break; 
            }
            temp = temp->next;
        }
        return head;
    }
};
