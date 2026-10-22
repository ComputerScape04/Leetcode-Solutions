class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // if the string is a single character or 0 characters
        int len = s.size();
        if (len == 0 || len == 1)
            return len;
        
        // if string is 2 or more characters
        int i = 0, j = 1;
        int substrLen = 1;

        // stores the character mapped to its position in the string
        unordered_map<char, int> mp; 
        mp[s[i]] = i;

        while(j != s.size()) {
            
            // check if s[j] is present in the hashmap.
            // if yes, it is a duplicate and thus we move the left pointer i
            // we also update the position of the character in the hashmap with j

            // duplicate
            if (mp.find(s[j]) != mp.end() && (i <= mp[s[j]] && mp[s[j]] <= j)) {
                i = mp[s[j]] + 1;
                mp[s[j]] = j; // update the position in the map
            }
            // new character
            else {
                mp[s[j]] = j;
                substrLen = max(substrLen, (j - i + 1));
            }

            j++;
        }

        return substrLen;
    }
};
