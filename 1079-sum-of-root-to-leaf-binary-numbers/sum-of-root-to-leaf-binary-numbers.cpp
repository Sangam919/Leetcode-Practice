/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int num, int& sum) {
        if (!root) return;

        // Build the binary number
        num = (num << 1) | root->val;

        // If leaf node, add the number to sum
        if (!root->left && !root->right) {
            sum += num;
            return;
        }

        dfs(root->left, num, sum);
        dfs(root->right, num, sum);
    }

    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
};