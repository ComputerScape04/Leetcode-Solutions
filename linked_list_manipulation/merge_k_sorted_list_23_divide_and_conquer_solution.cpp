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
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        ListNode dummy = ListNode(0);
        ListNode *curr = &dummy;

        while(l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        if (l1)
            curr->next = l1;
        else
            curr->next = l2;

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0)
            return nullptr;

        int i = 0;
        while(lists.size() > 1) {
            vector<ListNode*> mergedLists;
            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i + 1 > lists.size()-1) ? nullptr : lists[i+1];

                ListNode* sortedList = mergeLists(l1, l2);
                mergedLists.push_back(sortedList);
            }
            lists = mergedLists;
        }

        return lists[0];
    }
};
