class Solution {
public:
    int trap(vector<int>& height) {
        // Get the size of the height array
        int size = height.size();

        // Create a vector to store the maximum height to the left of each index
        vector<int> leftMax;
        
        // Initialize the first element of leftMax as the first element of height
        leftMax.push_back(height[0]);
        
        // Fill the leftMax array where each element is the maximum height to its left
        for (int i = 1; i < size; i++) {
            leftMax.push_back(max(leftMax[i-1], height[i]));
        }

        // Create a vector to store the maximum height to the right of each index
        vector<int> rightMax;

        // Initialize the first element of rightMax as the last element of height
        rightMax.push_back(height[size - 1]);

        // Use a variable j to store the current index in rightMax
        int j = 0;

        // Fill the rightMax array where each element is the maximum height to its right
        // Traverse the height array from right to left
        for (int i = size - 2; i >= 0; i--) {
            rightMax.push_back(max(rightMax[j], height[i]));
            j++;
        }

        // Reverse the rightMax array since we filled it in reverse order
        reverse(rightMax.begin(), rightMax.end());

        // Initialize sum to store the total trapped water
        int sum = 0;

        // Calculate the trapped water at each index
        for (int i = 0; i < size; i++) {
            // If the current height is less than both the maximum heights on its left and right
            if (height[i] < leftMax[i] && height[i] < rightMax[i]) {
                // Add the minimum of the two maximum heights minus the current height
                sum += min(leftMax[i], rightMax[i]) - height[i];
            }
        }

        // Return the total trapped water
        return sum;
    }
};
