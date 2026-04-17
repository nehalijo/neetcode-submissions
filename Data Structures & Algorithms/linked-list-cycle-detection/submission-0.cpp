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
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> nodes;
        ListNode* curr = head;
        while (curr != NULL) {
            if (nodes.count(curr) == 1) return true;
            nodes.insert(curr);
            curr = curr->next;
        }
        return false;
    }
};
