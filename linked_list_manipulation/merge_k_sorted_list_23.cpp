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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0)
            return 0;

        vector<int> arr;
        for (int i = 0; i < n; i++) {
            while(lists[i]) {
                arr.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }

        sort(arr.begin(), arr.end());

        ListNode dummy(0);
        ListNode* curr = &dummy;

        for (int val : arr) {
            curr->next = new ListNode(val);
            curr = curr->next;
        }

        return dummy.next;
    }
};
