class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int maxi = INT_MIN;
        int maxl = -1;
        int l = 0, r = k - 1;
        while (r < nums.size()) {
            if (maxl < l) {
                maxi = INT_MIN;
                for (int i = l; i <= r; i++) {
                    if (maxi < nums[i]) {
                        maxi = nums[i];
                        maxl = i;
                    }
                }
            }
            else if (maxi < nums[r]) {
                maxi = nums[r];
                maxl = r;
            }
            res.push_back(maxi);
            l++;
            r++;
        }
        return res;
    }
};
