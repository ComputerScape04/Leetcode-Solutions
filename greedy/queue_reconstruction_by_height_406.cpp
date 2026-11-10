class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end()); // sorts on height

        int n = people.size();
        int count = 0; // indicates how many numbers to the left must be greater than or equal to current number
        vector<vector<int>> result(n, vector<int>(2, -1));

        for (int i = 0; i < n; i++) {
            count = people[i][1];
            for (int j = 0; j < n; j++) {
                if (result[j][0] == -1) {
                    if (count == 0) {
                        result[j][1] = people[i][1];
                        result[j][0] = people[i][0];
                        break;
                    }
                    else
                        count--;
                }
                else if (people[i][0] <= result[j][0])
                    count = (count == 0) ? 0 : count-1;
            }
        }

        return result;
    }
};
