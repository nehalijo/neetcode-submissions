class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int longest = 0;
        unordered_set<char> cset;
        for(int right = 0; right < s.size(); right++) {
            while(cset.count(s[right]) == 1) {
                cset.erase(s[left]);
                left++;
            }
            cset.insert(s[right]);
            longest = max(longest, right - left + 1);
        }
        return longest;
    }
};
