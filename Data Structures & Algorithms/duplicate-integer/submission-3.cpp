class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int n: nums) {
            seen.insert(n);
        }
        return seen.size() < nums.size();
    }
};