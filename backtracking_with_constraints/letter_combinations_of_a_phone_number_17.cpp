class Solution {
public:
    void backtrack(const vector<vector<char>>& mp, vector<string>& result, string& digits, string curr, int i) {
        if (curr.size() == digits.size()) {
            result.push_back(curr);
            return;
        }
    
        if (i < digits.size()) {
            for (int j = 0; j < mp[digits[i] - '0'].size(); j++) {
                backtrack(mp, result, digits, curr + mp[digits[i] - '0'][j], i+1);
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        
        // construct the mapping
        vector<vector<char>> mp(10);

        char c = 'a';
        for (int i = 2; i < 10; i++) {
            for (int j = 0; j < ((i == 7 || i == 9) ? 4 : 3); j++)
                mp[i].push_back(c++);
        }

        vector<string> result;
        string curr = "";

        backtrack(mp, result, digits, curr, 0);
        return result;
    }
};
