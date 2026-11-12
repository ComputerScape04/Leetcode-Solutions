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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next)
            return head;

        int len = 0;
        ListNode* temp = head;
        while(temp) {
            len++;
            temp = temp->next;
        }

        ListNode dummy = ListNode(0);
        ListNode* prevTail = &dummy;
        prevTail->next = head;
        ListNode* tail = head;

        int n;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nex = curr->next;

        while(len >= k) {
            n = k;
            while(curr && n--) {
                curr->next = prev;
                prev = curr;
                curr = nex;
                if (nex)
                    nex = nex->next;
            }

            len -= k;

            // after the above while loop,
            // prev -> points to head to reversed group
            // curr -> points to end of next group
            // tail -> points to end of current group
            // prevTail -> points to end of prev group

            prevTail->next = prev;
            prevTail = tail;
            tail->next = curr;
            tail = curr;

            prev = nullptr;
        }

        return dummy.next;
    }
};
