/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* firstNode, TreeNode* secondNode) {
        if (root == nullptr) return nullptr;

        if (root == firstNode || root == secondNode)
            return root;

        TreeNode* leftResult = lowestCommonAncestor(root->left, firstNode, secondNode);
        TreeNode* rightResult = lowestCommonAncestor(root->right, firstNode, secondNode);

        if (leftResult != nullptr && rightResult != nullptr)
            return root;

        if (leftResult != nullptr)
            return leftResult;

        return rightResult;
    }
};
