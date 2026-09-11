class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) return nums;
        int maxi = INT_MIN;
        int maxl = -1;
        vector<int> res;
        for (int i = 0; i < k; i++) {
            if (maxi < nums[i]) {
                maxi = nums[i];
                maxl = i;
            }
        }
        res.push_back(maxi);
        int l = 1, r = k + 1;
        while (l < r && r <= nums.size()) {
            if (maxi < nums[r - 1]) {
                maxi = nums[r - 1];
                maxl = r - 1;
            } 
            else if (maxl < l) {
                maxi = INT_MIN;
                for (int i = l; i < r; i++) {
                    if (maxi < nums[i]) {
                        maxi = nums[i];
                        maxl = i;
                    }
                }
            }
            res.push_back(maxi);
            l++;
            r++;
        }
        return res;
    }
};
