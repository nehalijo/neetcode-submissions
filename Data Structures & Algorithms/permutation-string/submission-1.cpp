class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int l = 0;
        int r = s1.size() - 1;
        vector<int> freq1(26, 0);
        for (char c: s1) {
            freq1[c - 'a']++;
        }
        vector<int> freq2(26, 0);
        for (int i = l; i <= r; i++) {
            freq2[s2[i] - 'a']++;
        }
        while (r < s2.size()) {
            if (freq1 == freq2) return true;
            freq2[s2[l] - 'a']--;
            l++;
            r++;
            if (r < s2.size()) {
                freq2[s2[r] - 'a']++;
            }
        }
        return false;
    }
};
