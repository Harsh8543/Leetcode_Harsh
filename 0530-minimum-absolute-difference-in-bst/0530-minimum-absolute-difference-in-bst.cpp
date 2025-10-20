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
    void inorder(TreeNode* root, vector<int>& har) {
        if (root == NULL) return;
        inorder(root->left, har);
        har.push_back(root->val);
        inorder(root->right, har);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> har;
        inorder(root, har);
        int n = har.size();
        int tanu = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            if (har[i + 1] - har[i] < tanu) {
                tanu = har[i + 1] - har[i];
            }
        }
        return tanu;
    }
};
