class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) return 0;
        stack<int> ops;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int v1 = ops.top();
                ops.pop();
                int v2 = ops.top();
                ops.pop();
                if (tokens[i] == "+") {
                    ops.push(v2 + v1);
                } else if (tokens[i] == "-") {
                    ops.push(v2 - v1);
                } else if (tokens[i] == "*") {
                    ops.push(v2 * v1);
                } else if (tokens[i] == "/") {
                    ops.push(v2 / v1);
                }

            } else {
                ops.push(stoi(tokens[i]));
            }
        }
        return ops.top();
    }
};
