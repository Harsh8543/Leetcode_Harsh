class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
//                if(head == NULL || head->next == NULL || k == 0){
//             return head;
//         }

//         ListNode* temp = head;
//         int count = 0;
//         while(temp){
//             count++;
//             temp = temp->next;
//         }
//         while(k>count){
//             k = k - count;
//         }
//         if(k == count){
//             return head;
//         }

//         int t = count - k;

//         ListNode* tail = head;
//         for(int i=1; i<t; i++){
//             tail = tail->next;
//         }

//         ListNode* prevHead = head;
//         head = tail->next;
//         temp = head;

//         while(temp->next != NULL){
//             temp = temp->next;
//         }

//         tail->next = NULL;
//         temp->next = prevHead;

// return head;

    if(!head) return head;
        
        int len=1; 
        ListNode *newH, *tail;
        newH=tail=head;
        
        while(tail->next) 
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; 

        if(k %= len) 
        {
            for(auto i=0; i<len-k; i++)tail = tail->next; 
        }
        newH = tail->next; 
        tail->next = NULL;
        return newH;
    }
};