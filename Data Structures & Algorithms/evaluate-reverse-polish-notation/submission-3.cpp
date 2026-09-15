class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> ops;
        for (const string& c: tokens) {
            if (c == "+" || c == "-" || c == "*" || c == "/") {
                int a = ops.top();
                ops.pop();
                int b = ops.top();
                ops.pop();
                if (c == "+") ops.push(b + a);
                else if (c == "-") ops.push(b - a);
                else if (c == "*") ops.push(b * a);
                else ops.push(b / a);
            } else {
                ops.push(stoi(c));
            }
        }
        return ops.top();
    }
};
