class Solution {
public:
    bool isPalindrome(const string &s, int i, int j) {
        while(i < j && s[i] == s[j]) {
            i++;
            j--;
        }
        return (i < j) ? false : true;
    }

    void backtrack(const string& s, int start, vector<string>& palindromes, vector<vector<string>>& res) {
        if (start == s.size()) {
            res.push_back(palindromes);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                palindromes.push_back(s.substr(start, end - start + 1));

                // explore partition starting from end + 1
                backtrack(s, end + 1, palindromes, res);

                palindromes.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> palindromes;

        backtrack(s, 0, palindromes, res);

        return res;
    }
};
