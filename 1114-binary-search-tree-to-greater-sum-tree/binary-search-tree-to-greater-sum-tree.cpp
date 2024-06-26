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
    TreeNode* bstToGst(TreeNode* root) {
        int nodeSum = 0;
        bstToGstHelper(root, nodeSum);
        return root;
    }

private:
    void bstToGstHelper(TreeNode* root, int& nodeSum) {
        if (!root) {
            return;
        }

        bstToGstHelper(root->right, nodeSum);
        nodeSum += root->val;
        root->val = nodeSum;
        bstToGstHelper(root->left, nodeSum);
    }
};