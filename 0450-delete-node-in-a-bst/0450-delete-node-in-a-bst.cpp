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
 class Solution{
    private:
TreeNode* minValueNode(TreeNode* root) {
    TreeNode* current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
public:
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->val)
        root->left = deleteNode(root->left, key);

    else if (key > root->val)
        root->right = deleteNode(root->right, key);

    else {
        // Node found
        if (root->left == NULL)
            return root->right;

        else if (root->right == NULL)
            return root->left;

        TreeNode* temp = minValueNode(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}
 };