class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] < nums[r]) {
                //mid in rotated part. min is here
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        return nums[l];
    }
};
