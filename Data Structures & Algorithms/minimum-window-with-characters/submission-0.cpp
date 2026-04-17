class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> count;
        for(char c: t) {
            count[c]++;
        }
        int left = 0;
        string res = "";
        int needed = t.length();
        for(int right = 0; right < s.size(); right++) {
            if(count[s[right]] > 0) {
                needed--;
            }
            count[s[right]]--;
            while (needed == 0) {
                if ((res.length() > (right - left + 1)) || res.length() == 0) res = s.substr(left, right - left + 1);
                count[s[left]]++;
                if (count[s[left]] > 0) {
                    needed++;
                }
                left++;
            }
        }
        return res;
    }
};
