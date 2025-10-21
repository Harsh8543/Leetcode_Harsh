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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;
        
        vector<long long> levelSums;
        queue<TreeNode*> q;
        q.push(root);
        
        // Level order traversal
        while (!q.empty()) {
            int size = q.size();
            long long sum = 0;
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            levelSums.push_back(sum);
        }
        
        // Sort in descending order
        sort(levelSums.rbegin(), levelSums.rend());
        
        // If k is larger than number of levels
        if (k > levelSums.size()) return -1;
        
        return levelSums[k - 1];
    }
};