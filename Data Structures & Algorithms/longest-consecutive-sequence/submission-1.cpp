class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() == 0) return 0;
        int current = 1;
        int longest = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i+1]) continue;
            else if (nums[i] + 1 == nums[i+1]) current += 1;
            else current = 1;
            if (current > longest) longest = current;
        }
        return longest;
    }
};
