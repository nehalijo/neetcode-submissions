class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> freq;
        for (int n: nums) {
            freq[n]++;
        }
        for (auto &p: freq) {
            pq.push({p.second, p.first});
        }
        vector<int> res;
        while (k > 0) {
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res;
    }
};
