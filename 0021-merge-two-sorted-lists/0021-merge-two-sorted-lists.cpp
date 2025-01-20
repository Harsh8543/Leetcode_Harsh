class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
       if(!head1) return head2;
       if(!head2) return head1;
       ListNode* head=NULL;
       ListNode* tail=NULL;
       while(head1 && head2){
        ListNode* temp=NULL;
        if(head1->val<=head2->val){
            temp=new ListNode(head1->val);
            head1=head1->next;
        }
        else{
             temp=new ListNode(head2->val);
            head2=head2->next;
        }
        if(!head){
            head=temp;
            tail=temp;
        }else {
                tail->next = temp; 
                tail = temp;      
            }
        }
        if (head1) {
            tail->next = head1;
        }
        if (head2) {
            tail->next = head2;
        }
        return head;
       }
    
};