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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int len = 0;
        while (curr != NULL) {
            len++;
            curr = curr->next;
        }
        if (len - n == 0) return head->next; 
        int pos = 0;
        curr = head;
        ListNode* prev;
        while (curr->next != NULL && pos < (len-n)) {
            pos++;
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        return head;
    }
};
