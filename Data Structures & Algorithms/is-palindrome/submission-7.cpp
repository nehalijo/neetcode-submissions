class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        while (start < end) {
            while (isalnum(s[start]) == false and start < s.size()) start++;
            while (isalnum(s[end]) == false and end >= 0) end--;
            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
