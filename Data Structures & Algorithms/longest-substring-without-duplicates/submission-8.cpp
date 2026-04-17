class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //using hash map
        int longest = 0;
        int left = 0;
        int right = 0;
        unordered_map<char, int> mp;
        while (right < s.size()) {
            if(mp.find(s[right]) != mp.end()) {
                left = max(mp[s[right]] + 1, left);
            }
            mp[s[right]] = right;
            longest = max(longest, right - left + 1);
            right++;
        }
        return longest;
    }
};
