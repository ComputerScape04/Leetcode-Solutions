class Solution {
public:
    // 0 1 3 6 10 15 21 28
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        if (n == 1)
            return arr[0] % 2 ? 1 : 0;

        const int MOD = 1e9 + 7;
        long long subArrayCnt = 0;
        long long evenCnt = 0, oddCnt = 0;

        int i = 0, runningSum = 0;
        while(i < n) {
            runningSum += arr[i++];
            if (runningSum % 2)  {
                oddCnt++;
                subArrayCnt += (evenCnt + 1) % MOD;
            }
            else {
                evenCnt++;
                subArrayCnt += oddCnt % MOD;
            }
        }

        return subArrayCnt % MOD;
    }
};
