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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>har;
        if(!root) return har;
        RView(root,0,har);
        return har;

    }
    private:
    void RView(TreeNode* root,int level, vector<int>&har){
        if(!root) return;
        if(level==har.size()){
            har.push_back(root->val);
        }
        RView(root->right,level+1,har);
        RView(root->left,level+1,har);
       
    }
};