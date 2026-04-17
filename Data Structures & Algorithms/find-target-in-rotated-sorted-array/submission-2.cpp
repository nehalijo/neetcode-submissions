class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot = 0;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            if (nums[left] < nums[right]) {
                if (nums[pivot] > nums[left]) pivot = left;
                break;
            }
            int mid = (left + right) / 2;
            if (nums[pivot] > nums[mid]) pivot = mid;
            if (nums[left] <= nums[mid]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        if (pivot == 0) {
            left = 0;
            right = nums.size() - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (target == nums[mid]) return mid;
                if (target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
        }
        if (target < nums[0]) {
            left = pivot;
            right = nums.size() - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (target == nums[mid]) return mid;
                if (target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
        }
        else {
            left = 0;
            right = pivot - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (target == nums[mid]) return mid;
                if (target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }
};
