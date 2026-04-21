class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int n: nums) {
            count[n]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto &p: count) {
            pq.push({p.second, p.first});
        }
        vector<int> result;
        while (k > 0) {
            result.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return result;
    }
};
