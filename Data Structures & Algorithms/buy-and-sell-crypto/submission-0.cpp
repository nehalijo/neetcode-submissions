class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        for(int i = 0; i < prices.size(); i++) {
            for(int j = i+1; j < prices.size(); j++) {
                int currP = prices[j] - prices[i];
                if(currP > maxP) maxP = currP;
            }
        }
        return maxP;
    }
};
