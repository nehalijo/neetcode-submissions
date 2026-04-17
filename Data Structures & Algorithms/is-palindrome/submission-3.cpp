class Solution {
public:
    bool isPalindrome(string s) {
        string news = "";
        int i = 0;
        while (i < s.size()) {
            if ('0' <= s[i] and s[i] <= '9') news += s[i];
            else if (('a' <= s[i] and s[i] <= 'z') or ('A' <= s[i] and s[i] <= 'Z')) {
                news += tolower(s[i]);
            }
            i++;
        }
        int len = news.size();
        if (news == "" or len == 1) return true;
        int flag = true;
        for(int i = 0; i < len / 2; i++) {
            if (news[i] != news[len - i - 1]) {
                flag = false;
                break;
            }
        }
        return flag;
    }
};
