class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
                int m = (l + r) / 2;
                if (nums[m] < nums[r]) r = m;
                else l = m + 1;
        }
        int pivot = l;
        l = 0;
        r = nums.size() - 1;
        if (target >= nums[pivot] && target <= nums[r]) l = pivot;
        else r = pivot - 1;
        return binarySearch(nums, target, l, r);
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
