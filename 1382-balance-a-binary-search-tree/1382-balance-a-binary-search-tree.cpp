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
    void inOrder(TreeNode* root,vector<int>&vec){
        if(!root) return;

        inOrder(root->left,vec);
        vec.push_back(root->val);
        inOrder(root->right,vec);
    }
    TreeNode* construct(vector<int>&vec,int low,int high){
        if(low>high) return NULL;

        int mid=low+(high-low)/2;
        TreeNode* newNode=new TreeNode(vec[mid]);
        newNode->left=construct(vec,low,mid-1);
        newNode->right=construct(vec,mid+1,high);
        return newNode;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>vec;
        inOrder(root,vec);
        return construct(vec,0,vec.size()-1);
    }
};