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
private:
    int res = 0, last = 0;
    void dfs(TreeNode* root , int curr){
        if(!root) return;
        if(curr == last){
            res = root->val;
            ++last;
        }
        dfs(root->left , curr + 1);
        dfs(root->right , curr + 1);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        dfs(root , 0);
        return res;
    }
};