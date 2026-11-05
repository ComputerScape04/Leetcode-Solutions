class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // sort according to the start time
        sort(arr.begin(), arr.end());
        
        // check for overlaps
        int n = arr.size();
        for (int i = 0; i < n-1; i++) {
            if (arr[i][1] > arr[i+1][0])
                return false;
        }
        
        return true;
    }
};
