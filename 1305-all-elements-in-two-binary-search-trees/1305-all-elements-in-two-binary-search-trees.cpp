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
    void inorder(TreeNode* root1, TreeNode* root2, vector<int>& har) {
        if (root1 == NULL && root2 == NULL) return;

        inorder(root1 ? root1->left : NULL, root2 ? root2->left : NULL, har);

        if (root1 != NULL) har.push_back(root1->val);
        if (root2 != NULL) har.push_back(root2->val);

        inorder(root1 ? root1->right : NULL, root2 ? root2->right : NULL, har);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> har;
        inorder(root1, root2, har);
        sort(har.begin(), har.end()); 
        return har;
    }
};
