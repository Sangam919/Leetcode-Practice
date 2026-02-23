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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* curr = head;
        ListNode* newHead = head->next;  // second node will become head
        ListNode* prev = NULL;

        while (curr != NULL && curr->next != NULL) {
            ListNode* next = curr->next;
            ListNode* nextPair = next->next;

            // swap
            next->next = curr;
            curr->next = nextPair;

            // connect previous pair
            if (prev != NULL)
                prev->next = next;

            prev = curr;
            curr = nextPair;
        }

        return newHead;
    }
};