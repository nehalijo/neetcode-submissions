class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int longest = 1;
        int curr = 1;
        int start = 0;
        int end = 1;
        for (int i = 0; i < s.size(); i++) {
            unordered_set<char> cset;
            cset.insert(s[i]);
            for (int j = i + 1; j < s.size(); j++) {
                if (cset.count(s[j]) == 1) {
                    break;
                }
                else {
                    cset.insert(s[j]);
                }
            }
            longest = max(longest, int(cset.size()));
        }
        return longest;
    }
};
