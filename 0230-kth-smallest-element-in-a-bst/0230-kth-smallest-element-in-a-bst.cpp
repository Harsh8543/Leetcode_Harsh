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
// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         vector<int>har;
//         if(root==NULL) return;
// inorder(root,k,har);
// int n=har.size();
//       for(int i=0;i<n;i++){
//         if(i==k){
//             return har[i];
//         }
//         return -1;
//       }
//     }
//     private:
//     void inorder(TreeNode* root,int &k,vector<int>&har)
//      inorder(root->left,har);
//      har.push_back(root->val);
//      inorder(root->right,har);
      
// };



class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> har;
        if (root == NULL) return 0;
        inorder(root, har);
        int n = har.size();
        for (int i = 0; i < n; i++) {
            if (i == k - 1) {  
                return har[i];
            }
        }
        return -1; 
    }
private:
    void inorder(TreeNode* root, vector<int>& har) {
        if (root == NULL) return;
        inorder(root->left, har);
        har.push_back(root->val);
        inorder(root->right, har);
    }
};
