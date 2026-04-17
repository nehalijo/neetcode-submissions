class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> count;
        for (char c: t) {
            count[c]++;
        }

        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;
        int left = 0;
        int needed = t.length();
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            if (count[c] > 0) {
                needed--;
            }  
            count[c]--;
            while(needed == 0) {
                if (resLen > (right - left + 1)) {
                    resLen = right - left + 1;
                    res = {left, right};
                }
                if (count[s[left]] == 0) needed++;
                count[s[left]]++;
                left++;
            }
        }
        return resLen == INT_MAX ? "": s.substr(res.first, resLen); 
    }
};
