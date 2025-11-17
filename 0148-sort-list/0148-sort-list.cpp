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
    ListNode* sortList(ListNode* head) {
        vector<int> har;
        ListNode* temp = head;
        while (temp != NULL) {
            har.push_back(temp->val);
            temp = temp->next;
        }
        sort(har.begin(), har.end());
        temp = head;
        int i = 0;
        while (temp != NULL) {
            temp->val = har[i++];
            temp = temp->next;
        }
        return head;
    }
};
