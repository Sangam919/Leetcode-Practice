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
    vector<vector<int>> result;

    void dfs(TreeNode* root, int targetSum, vector<int>& path) {
        if(root == NULL) return;

        path.push_back(root->val);

        // leaf node
        if(root->left == NULL && root->right == NULL) {
            if(targetSum == root->val) {
                result.push_back(path);
            }
        }

        dfs(root->left, targetSum - root->val, path);
        dfs(root->right, targetSum - root->val, path);

        // backtracking
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return result;
    }
};
