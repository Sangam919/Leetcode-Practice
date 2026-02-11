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
    int sum(TreeNode* root, int low, int high) {
        if(!root) return 0;
        int cnt = 0;
        if(root->val >= low && root->val <= high){
            cnt = cnt + root->val;
        }
            cnt = cnt + sum(root->left,low,high);
            cnt = cnt + sum(root->right,low,high);
            return cnt;
        }
        int rangeSumBST(TreeNode* root, int low,int high){
            return sum(root,low,high);
    }
};
