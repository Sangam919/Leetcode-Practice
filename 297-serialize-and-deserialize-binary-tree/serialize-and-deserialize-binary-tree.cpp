/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void buildString(TreeNode* root, string &ans) {
        if (root == NULL) {
            ans += "null,";
            return;
        }
        
        ans += to_string(root->val) + ",";
        buildString(root->left, ans);
        buildString(root->right, ans);
    }

    string serialize(TreeNode* root) {
        string ans = "";
        buildString(root, ans);
        return ans;
    }

    TreeNode* buildTree(vector<string>& nodes, int &i) {
        if (nodes[i] == "null") {
            i++;
            return NULL;
        }
        
        TreeNode* root = new TreeNode(stoi(nodes[i]));
        i++;
        
        root->left = buildTree(nodes, i);
        root->right = buildTree(nodes, i);
        
        return root;
    }

    TreeNode* deserialize(string data) {
        vector<string> nodes;
        stringstream ss(data);
        string item;
        
        while (getline(ss, item, ',')) {
            nodes.push_back(item);
        }
        
        int i = 0;
        return buildTree(nodes, i);
    }
};
