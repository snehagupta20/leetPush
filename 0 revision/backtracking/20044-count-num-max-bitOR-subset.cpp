class Solution {
public:

    int backtrack(vector<int>& nums, int index, int current_or, int max_or) {
        // if we've processed all elements
        if (index == nums.size()) {
            return (current_or == max_or) ? 1 : 0;
        }

        // count the subsets including nums[index] and excluding nums[index]
        int include = backtrack(nums, index + 1, current_or | nums[index], max_or); // Include nums[index]
        int exclude = backtrack(nums, index + 1, current_or, max_or);               // Exclude nums[index]
        
        return include + exclude;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int max_or = 0;
        for (int num : nums) {
            max_or |= num;  // OR all numbers to get the maximum OR possible
        }

        // start the backtracking process
        return backtrack(nums, 0, 0, max_or);

    }
};