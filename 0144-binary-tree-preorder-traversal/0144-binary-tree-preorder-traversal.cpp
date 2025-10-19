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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>tanu;
        preorder(root,tanu);
        return tanu;
    }
    private:
    void preorder(TreeNode* root, vector<int>&tanu){
       if(root==NULL){
        return;
       }
       tanu.push_back(root->val);
       preorder(root->left,tanu);
       preorder(root->right,tanu);
      
    }
};