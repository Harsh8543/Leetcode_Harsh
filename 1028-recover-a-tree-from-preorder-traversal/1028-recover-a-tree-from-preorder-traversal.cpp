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
  int index = 0; 
    TreeNode* recoverFromPreorder(string traversal) {
         return buildTree(traversal, 0);
    }
    private:
    TreeNode* buildTree(string& s, int depth) {
        int dashCount = 0;
        // Count the number of dashes to determine depth
        while (index < s.size() && s[index] == '-') {
            dashCount++;
            index++;
        }

        // If dashes do not match expected depth, return NULL
        if (dashCount != depth) {
            index -= dashCount;  // Backtrack dashes
            return NULL;
        }

        // Read the node value
        int num = 0;
        while (index < s.size() && isdigit(s[index])) {
            num = num * 10 + (s[index] - '0');
            index++;
        }

        // Create a new TreeNode
        TreeNode* node = new TreeNode(num);

        // Recursively construct left and right subtrees
        node->left = buildTree(s, depth + 1);
        node->right = buildTree(s, depth + 1);

        return node;
    }
};