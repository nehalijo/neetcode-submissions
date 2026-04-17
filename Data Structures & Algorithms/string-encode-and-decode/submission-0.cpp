class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for (string s: strs) {
            int l = s.size();
            encoded.append(to_string(l));
            encoded.append("#");
            encoded.append(s);
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        while(i < s.size()) {
            string l = "";
            while (s[i] != '#') {
                l += s[i];
                i++;
            }
            int len = stoi(l);
            decoded.push_back(s.substr(i+1, len));
            i += 1 + len;
        }
        return decoded;
    }
};
