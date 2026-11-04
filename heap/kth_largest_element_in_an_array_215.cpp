class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int> pq; // max heap solution
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int x : nums) {
            minHeap.push(x);
            if (minHeap.size() > k) minHeap.pop();
        }
        
        // int temp = k-1;
        // while(temp-- > 0)
        //     pq.pop();

        return minHeap.top();  
    }
};
