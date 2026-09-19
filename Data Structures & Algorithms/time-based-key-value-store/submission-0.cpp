class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> tm;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        tm[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>>& v = tm[key];
        int l = 0;
        int r = v.size() - 1;
        string res = "";
        while (l <= r) {
            int m = (l + r) / 2;
            if (v[m].first <= timestamp) {
                res = v[m].second;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return res; 
    }
};
