/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* curr;

    TreeNode* buildBST(int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode* leftChild = buildBST(left, mid - 1);

        TreeNode* root = new TreeNode(curr->val);
        curr = curr->next;

        root->left = leftChild;
        root->right = buildBST(mid + 1, right);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }

        curr = head;
        return buildBST(0, n - 1);
    }
};




// class Solution {
// public:
//     TreeNode* buildBST(vector<int>& nums, int left, int right) {
//         if (left > right) return nullptr;

//         int mid = left + (right - left) / 2;
//         TreeNode* root = new TreeNode(nums[mid]);

//         root->left = buildBST(nums, left, mid - 1);
//         root->right = buildBST(nums, mid + 1, right);

//         return root;
//     }

//     TreeNode* sortedListToBST(ListNode* head) {
//         vector<int> nums;

//         while (head != nullptr) {
//             nums.push_back(head->val);
//             head = head->next;
//         }

//         return buildBST(nums, 0, nums.size() - 1);
//     }
// };
