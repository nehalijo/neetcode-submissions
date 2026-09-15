class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
        stack<pair<int,int>> stk;
        for (int i = 0; i < temperatures.size(); i++) {
            int t = temperatures[i];
            while (!stk.empty() && stk.top().first < t) {
                auto pair = stk.top();
                result[pair.second] = i - pair.second;
                stk.pop();
            }
            stk.push({t, i});
        }
        return result;
    }
};
