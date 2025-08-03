class Solution {
    public:
        long long maximumSubarraySum(vector<int>& nums, int k) {
            map<int,int> freq;
            long long currsum=0;
            int end=0;
            int start=0;
            long long sum =0;
            for(end=0;end<nums.size();end++){
                freq[nums[end]]++;
                currsum+=nums[end];
    
                if(end - start + 1 > k){
                    freq[nums[start]]--;
                    if(freq[nums[start]]==0){
                        freq.erase(nums[start]);
                    }
                    currsum-=nums[start];
                    start++;
                }
    
                if(end - start + 1 == k && freq.size()==k){
                    sum=max(sum, currsum);
                }
            }
    
            return sum;
        }
    };