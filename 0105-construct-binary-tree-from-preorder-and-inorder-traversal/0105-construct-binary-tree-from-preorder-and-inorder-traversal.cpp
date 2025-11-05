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
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd,
                    unordered_map<int,int>& inmap) {
        
        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        // Root from preorder
        TreeNode* root = new TreeNode(preorder[preStart]);

        // Find root index in inorder
        int inRoot = inmap[root->val];
        
        // Count elements in left subtree
        int numsLeft = inRoot - inStart;

        // Build left subtree
        root->left = build(preorder,preStart + 1,preStart + numsLeft,inorder,inStart,inRoot - 1, inmap);

        // Build right subtree
        root->right = build(preorder,
                            preStart + numsLeft + 1,
                            preEnd,
                            inorder,
                            inRoot + 1,
                            inEnd,
                            inmap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inmap;
        for (int i = 0; i < inorder.size(); i++)
            inmap[inorder[i]] = i;
        
        return build(preorder, 0, preorder.size()-1,
                     inorder, 0, inorder.size()-1,
                     inmap);
    }
};
