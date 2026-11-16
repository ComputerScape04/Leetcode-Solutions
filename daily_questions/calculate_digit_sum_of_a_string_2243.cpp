/* My Solution */
class Solution {
public:
    string parseString(string s) {
        int sum = 0;
        for (char c : s) {
            switch(c) {
                case '0': sum += 0; break;
                case '1': sum += 1; break;
                case '2': sum += 2; break;
                case '3': sum += 3; break;
                case '4': sum += 4; break;
                case '5': sum += 5; break;
                case '6': sum += 6; break;
                case '7': sum += 7; break;
                case '8': sum += 8; break;
                case '9': sum += 9; break;
            }
        }

        return to_string(sum);
    }

    string digitSum(string s, int k) {
        while(s.size() > k) {
            string new_s = "", temp = "";
            for (int i = 0; i < s.size(); i++) {
                if (i==0 || i % k)
                    temp += s[i];
                else {
                    new_s += parseString(temp);
                    temp = s[i];
                }
            }
            if (temp.size())
                new_s += parseString(temp);
            s = new_s;
        }

        return s;
    }
};

/* Optimal Solution */
class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k) {
            string next_s = "";
            for (int i = 0; i < s.size(); i+=k) {
                int sum = 0;
                for (int j = i; j < min((int)s.size(), i + k); j++)
                    sum += s[j] - '0';
                next_s += to_string(sum);
            }
            s = next_s;
        }
        return s;
    }
};
