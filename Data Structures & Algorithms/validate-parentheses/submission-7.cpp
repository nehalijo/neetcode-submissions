class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(') st.push(')');
            else if (c == '{')  st.push('}');
            else if (c == '[') st.push(']');
            else if (st.empty()) return false;
            else if (st.top() == c) st.pop();
            else return false;
        }
        return st.empty();
    }
};
