class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max = -1;
        for(int i = 0; i < heights.size(); i++) {
            for (int j = i+1; j < heights.size(); j++) {
                int curr_area = -1;
                if (heights[i] > heights[j]) {
                    curr_area = (j-i) * heights[j];
                }
                else {
                    curr_area = (j-i) * heights[i];
                }
                if (curr_area > max) max = curr_area; 
            }
        }
        return max;
    }
};
