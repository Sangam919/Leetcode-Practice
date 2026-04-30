class Solution {
public:
    void dfs(TreeNode* root, int level, vector<int>& ans) {
        if(root == NULL) return;

        if(level == ans.size()) {
            ans.push_back(root->val);
        } else {
            ans[level] = max(ans[level], root->val);
        }

        dfs(root->left, level + 1, ans);
        dfs(root->right, level + 1, ans);
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
};