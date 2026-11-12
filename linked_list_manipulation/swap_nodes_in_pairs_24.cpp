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
        if (!head || !head->next)
            return head;

        // helps create connection from pair i-1 to pair i
        ListNode dummy = ListNode(0);
        ListNode* prev = &dummy;

        ListNode* left = head;
        ListNode* mid = left->next;
        ListNode* right = mid->next;

        while(left && mid) {
            // connect i to i-1
            mid->next = left;
            // connect i-1 to i+1
            left->next = right;

            // create connection from pair i-1 to i
            prev->next = mid;
            prev = mid->next;
    
            // advance pointers
            left = right;
            if (left)
                mid = left->next;
            if (mid)
                right = mid->next;
        }

        return dummy.next;
    }
};
