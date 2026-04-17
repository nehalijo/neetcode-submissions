class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> pres(len, 1);
        vector<int> posts(len, 1);
        vector<int> result;
        for (int i = 0; i < len; i++) {
            if (i == 0) {
                pres[i] = 1;
            }
            else {
                pres[i] = pres[i-1] * nums[i-1];
            }
        }
        for (int i = len - 1; i >= 0; i--) {
            if (i == len - 1) posts[i] = 1;
            else {
                posts[i] = posts[i+1] * nums[i+1];
            }
        }
        for (int i = 0; i < len; i++) {
            int product = pres[i] * posts[i];
            result.push_back(product); 
        }
        return result;
    }
};
