class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols + 1, 0); // Include an extra element for easier calculation
        int maxArea = 0;
        
        // making histogram of matrix
        for (const auto& row : matrix) {
            for (int i = 0; i < cols; i++) {
                heights[i] = (row[i] == '1') ? heights[i] + 1 : 0;
            }
            
            
            int n = heights.size(); 
            
            // Calculate max area using histogram method
            for (int i = 0; i < n; i++) {
                int minHeight = INT_MAX
                for (int j = i; j < n; j++) {
                    minHeight = min(minHeight, heights[j]);
                    int area = minHeight * (j - i + 1);
                    maxArea = max(maxArea, area);
                }
            }
        }
        
        return maxArea;
    }
};