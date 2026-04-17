class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int longest = 1;
        int curr;
        for(int i = 0; i < s.size(); i++) {
            curr = 0;
            unordered_set<char> cset;
            for(int j = i; j < s.size(); j++) {
                if (cset.count(s[j]) == 1) {
                    break;
                }
                else {
                    curr++;
                    cset.insert(s[j]);
                }
            }
            longest = max(longest, curr);
        }
        return longest;
    }
};
