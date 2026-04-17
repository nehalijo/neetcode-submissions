class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        while (start < end) {
            while (start < s.size() and isalnum(s[start]) == false) start++;
            while (end >= 0 and isalnum(s[end]) == false) end--;
            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
