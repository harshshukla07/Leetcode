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
    bool isEvenOddTree(TreeNode* root) {
        TreeNode* current = root;
        return dfs(current, 0);
    }

private:
    vector<int> prev;
    bool dfs(TreeNode* current, size_t level) {
        // Base case, an empty tree is Even-Odd
        if (current == nullptr) {
            return true;
        }

        
        if (current->val % 2 == level % 2) {
            return false;
        }

        
        prev.resize(max(prev.size(), level + 1));

        if (prev[level] != 0 && 
                ((level % 2 == 0 && current->val <= prev[level]) ||
                 (level % 2 == 1 && current->val >= prev[level]))) {
            return false;  
        }

        prev[level] = current->val;

        
        return dfs(current->left, level + 1) && dfs(current->right, level + 1);
    }
};
