class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        vector<pair<int, int>> freqvec(freq.begin(), freq.end());
        sort(freqvec.begin(), freqvec.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(freqvec[i].first);
        }
        return result;
    }
};
