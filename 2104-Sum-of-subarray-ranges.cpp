class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

        long long sum=0;
        int min_num=INT_MAX;
        int max_num=INT_MIN;

        for(int i=0;i<nums.size();i++){

            min_num=nums[i];
            max_num=nums[i];
            
            for(int j=i+1;j<nums.size();j++){

                min_num=min(min_num,nums[j]);
                max_num=max(max_num,nums[j]);

                sum+=(max_num-min_num);
            }
        }

        return sum;
    }
};

// - sare subarrays nikalo
// - find min element
// - find largest element
// - diff karo
// - sum kardo
