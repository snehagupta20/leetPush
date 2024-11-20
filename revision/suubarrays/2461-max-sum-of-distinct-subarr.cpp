class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map<int, int> freq; 
        long long maxSum = 0, currentSum = 0;
        int start = 0;

        for (int end = 0; end < nums.size(); end++) {
            freq[nums[end]]++;
            currentSum += nums[end];

            if (end - start + 1 > k) {
                freq[nums[start]]--;
                if (freq[nums[start]] == 0) {
                    freq.erase(nums[start]);
                }
                currentSum -= nums[start];
                start++;
            }

            if (end - start + 1 == k && freq.size() == k) {
                maxSum = max(maxSum, currentSum);
            }
        }

        return maxSum;
    }
};
