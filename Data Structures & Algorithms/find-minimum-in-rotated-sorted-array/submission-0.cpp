class Solution {
public:
    int findMin(vector<int> &nums) {
        int min = INT_MAX;
        for(int n: nums) {
            if (n < min) min = n;
        }
        return min;
    }
};
