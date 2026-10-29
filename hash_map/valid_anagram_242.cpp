class Solution {
public:
    bool isAnagram(string s, string t) {
        // if the strings are different length, then not an anagram
        if (s.size() != t.size())
            return false;

        unordered_map<char, int> mp;
        
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            mp[t[i]]--;
        }

        for (auto e : mp)
            if (e.second != 0)
                return false;
        
        return true;
    }
};
