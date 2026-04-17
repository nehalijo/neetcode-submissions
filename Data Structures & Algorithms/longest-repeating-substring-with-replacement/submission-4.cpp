class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        unordered_map<char, int> count;
        int left = 0;
        int maxF = 0;
        for(int right = 0; right < s.size(); right++) {
            count[s[right]]++;
            maxF = max(maxF, count[s[right]]);
            while((right - left + 1) - maxF > k) {
                count[s[left]]--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
