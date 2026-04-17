class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int l = 0;
        int r = 1;
        while (r < prices.size()) {
            if (prices[l] < prices[r]) {
                int currP = prices[r] - prices[l];
                if (currP > maxP) maxP = currP;
            }
            else l = r;
            r++;
        }
        return maxP;
    }
};
