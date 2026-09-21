class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> merged(n + m);
        copy(nums1.begin(), nums1.end(), merged.begin());
        copy(nums2.begin(), nums2.end(), merged.begin() + n);
        sort(merged.begin(), merged.end());
        int totalLen = merged.size();
        if (totalLen % 2 == 0) {
            return ((merged[totalLen / 2 - 1] + 
            merged[totalLen / 2]) / 2.0);
        } else return merged[totalLen / 2];
    }
};
