

class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            int low=0;
            int high=nums.size()-1;
            
            while(low<=high){
                if(nums[low]==target || nums[high] == target){
                    return true;
                }
                else if(nums[low]>target || nums[high]>target){
                    high--;
                }
                else if(nums[low]<target || nums[high]<target){
                    low++;
                }
                else{
                    low++;
                    high--;
                }
            }
    
            return false;
        }
    };