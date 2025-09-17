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
    int height(ListNode* head){
        int cnt=0;
        ListNode*temp=head;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }
public:
    ListNode* middleNode(ListNode* head) {
        
         int k = height(head); 
         int mid=k/2;
         int c=0;
         ListNode*temp=head;
         while(temp!=NULL){
            if(c==mid){
                return temp;
            }
           temp=temp->next;
            c++;
         }
         return head;


    //  while (temp != NULL) {
    //         if (c == mid) {
    //             return temp; 
    //         }
    //         temp = temp->next;
    //         c++;
    //     }
    //     return head;
    }
};