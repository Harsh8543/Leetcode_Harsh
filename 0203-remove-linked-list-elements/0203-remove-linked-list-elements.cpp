class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Step 1: Remove leading nodes with value == val
        while (head != nullptr && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        // Step 2: Traverse the rest of the list
        ListNode* curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->next->val == val) {
                ListNode* temp = curr->next;   // node to delete
                curr->next = temp->next;       // bypass node
                delete temp;                   // free memory
            } else {
                curr = curr->next;             // move ahead
            }
        }

        return head;


    //  while (head != nullptr && head->val == val) {
    //         ListNode* temp = head;
    //         head = head->next;
    //         delete temp;
    //     }

    //     ListNode* curr = head;
    //     while (curr != nullptr && curr->next != nullptr) {
    //         if (curr->next->val == val) {
    //             ListNode* temp = curr->next;
    //             curr->next = curr->next->next;
    //             delete temp;
    //         } else {
    //             curr = curr->next;
    //         }
    //     }

    //     return head;
    }
};