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
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
         if (head == NULL || head->next == NULL) return NULL;
        int k=height(head);
        int mid=k/2;
        int l=1;
        ListNode* temp1=head;
        while(temp1!=NULL){
            if(l==mid){
                temp1->next=temp1->next->next;
            }
            
            temp1=temp1->next;
            l++;
        }
        return head;
    }
};