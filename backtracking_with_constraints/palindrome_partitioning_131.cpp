/*

each substring must be a palindrome
-- 2 pointer involved maybe?

start partitioning the string from i = 1 to size of s
for each partition size, check if each partition is a palindrome
for partition size = 1, no need to check, just insert directly
for partition size > 1, check if string of size partition size is a palindrome,
    if it is, then push it to a vector
    if it is not, push the first character of the substring to the vector, 
        and continue adding the next character
*/

class Solution {
public:
    bool isPalindrome(const string &s, int i, int j) {
        while(i < j && s[i++] == s[j--]);
        return (i < j) ? false : true;
    }

    void backtrack(const string& s, vector<string>& palindromes, string curr, int idx, int partition_size, bool wasPushed) {
        if (curr.size() == partition_size) {
            // check if the constructed string is a palindrome
            if (partition_size == 1 || isPalindrome(curr, 0, curr.size()-1)) {
                palindromes.push_back(curr);
                wasPushed = true;
                return;
            }

            wasPushed = false;
            return;
        }

        if (idx < s.size())
            backtrack(s, palindromes, curr + s[idx], idx+1, partition_size);

        if (wasPushed) {
            curr = "";
        }

        if (idx < s.size())
            backtrack(s, palindromes, curr, idx + 1, partition_size);
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();

        vector<vector<string>> res;
        vector<string> palindromes;

        // from partition size 1 to n
        for (int i = 1; i <= n; i++) {
            backtrack(s, palindromes, "", 0, i, false);
            res.push_back(palindromes);
            palindromes = {};
        }

        return res;
    }
};
