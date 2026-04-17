class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> posts(len, 1);
        vector<int> result(len, 1);
        for (int i = 0; i < len; i++) {
            if (i == 0) {
                result[i] = 1;
            }
            else {
                result[i] = result[i-1] * nums[i-1];
            }
        }
        for (int i = len - 1; i >= 0; i--) {
            if (i == len - 1) posts[i] = 1;
            else {
                posts[i] = posts[i+1] * nums[i+1];
            }
        }
        for (int i = 0; i < len; i++) {
            result[i] *= posts[i];
        }
        return result;
    }
};
