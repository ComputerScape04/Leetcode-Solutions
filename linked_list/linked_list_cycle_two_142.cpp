/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // commented the following to consider O(1) memory solution
        // unordered_map<ListNode*, int> mp; // store node value along with the index

        ListNode* slow = head; // use this to get the index
        ListNode* fast = head; // use this to identify if there is a cycle or not.

        while(fast != nullptr && fast->next != nullptr) {
            // commented the following to consider O(1) memory solution
            // found start of the cycle
            // if (mp.find(slow) != mp.end()) 
            //     return slow;
            
            // mp[slow] = 1;

            // move both pointers
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                break;
        }

        if (fast == nullptr || fast->next == nullptr)
            return nullptr;

        // this probably works because, wherever slow and fast meet, that node is most likely
        // equal distance to the start of the cycle as the head.
        ListNode* slow2 = head;
        while(slow != slow2) {
            slow = slow->next;
            slow2 = slow2->next;
        }

        return slow;
    }
};
