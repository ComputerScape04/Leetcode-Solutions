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
        int k = lists.size();
        if (k == 0)
            return nullptr;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minpq;

        ListNode dummy = ListNode(0);
        ListNode *curr = &dummy;

        for (int i = 0; i < k; i++) {
            if (lists[i])
                minpq.push({lists[i]->val, i});
        }

        while(!minpq.empty()) {
            // get the smallest element from min heap and make a node
            ListNode *node = new ListNode(minpq.top().first);
            curr->next = node;
            curr = curr->next;

            // move the ptr from ith linked list
            int idx = minpq.top().second;
            lists[idx] = lists[idx]->next;
            minpq.pop();

            if (lists[idx])
                minpq.push({lists[idx]->val, idx});
        }

        return dummy.next;
    }
};
