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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL; // Base case: if list is empty, return NULL
        if (!head->next) return new TreeNode(head->val); // Single node case

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        // Find the middle node (slow) using fast and slow pointers
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Disconnect the left half from the middle
        if (prev) prev->next = NULL;

        // Create the root node with the middle element
        TreeNode* root = new TreeNode(slow->val);

        // Recursively construct the left and right subtrees
        if (head != slow) root->left = sortedListToBST(head); // Left subtree
        root->right = sortedListToBST(slow->next); // Right subtree

        return root;    
    }
};