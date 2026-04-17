class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        if (nums.size() == 0) return 0;
        for(int n: nums) {
            s.insert(n);
        }
        int longest = 1;
        for(int n: s ) {
            if (s.count(n-1) == 0) {
                int currNum = n;
                int curr = 1;
                while(s.count(currNum + 1) == 1) {
                    curr++;
                    currNum++;
                }
                longest = max(longest, curr);
            }
        }
        return longest;
    }
};
