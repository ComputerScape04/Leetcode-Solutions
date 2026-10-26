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
        // get the length of the linked list
        int len = 0;
        ListNode* temp = head;

        while(temp != nullptr) {
            len++;
            temp = temp->next;
        }

        // convert problem from "end of the linked-list" to "start of the linked-list"
        int new_n = len - n;
        ListNode* slow = head; // will be behind new_n'th node
        ListNode* fast = head->next; // will be on new_n'th node

        // if deleting first node, return fast (because it points to one ahead of slow)
        if (new_n == 0)
            return fast;

        int i = 1;
        while(i < new_n) {
            slow = slow->next;
            fast = fast->next;
            i++;
        }

        temp = fast->next;
        slow->next = temp;

        return head;
    }
};
