class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size());
        int product = 1;
        int sero = 0;
        for(int n: nums) {
            if (n != 0) {
                product *= n;
            }
            else sero++;
        }
        if (sero > 1) product = 0;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == 0) result[i] = product;
            else if (sero > 0) result[i] = 0;
            else result[i] = product / nums[i];
            i++;
        }
        return result;
    }
};
