class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        if (nums.size() == 0) return 0;
        for(int n: nums) {
            s.insert(n);
        }
        int longest = 1;
        for(int n: nums) {
            int i = 1;
            int curr = 1;
            while(s.count(n+i) == 1) {
                curr++;
                i++;
            }
            if (curr > longest) longest = curr; 
        }
        return longest;
    }
};
