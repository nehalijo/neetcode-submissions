class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
                int m = (l + r) / 2;
                if (nums[m] < nums[r]) {
                        r = m;
                }
                else {
                        l = m + 1;
                }
        }
        int pivot = l;
        int res = binarySearch(nums, target, 0, pivot - 1);
        if (res != -1) return res;
        return binarySearch(nums, target, pivot, nums.size() - 1);

    }
    int binarySearch(vector<int>& nums, int target, int left, int right) {
        while(left <= right) {
                int mid = (left + right) / 2;
                if (nums[mid] == target) return mid;
                if (target < nums[mid]) right = mid - 1;
                else left = mid + 1;
        }
        return -1;
    }
};
