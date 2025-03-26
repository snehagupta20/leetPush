class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            sort(nums.begin(),nums.end()); 
            int i=0;    
            while(i<nums.size()){
                if(i+1<nums.size() && (nums[i] ^ nums[i+1]) == 0){
                    i+=2;
                }
                else{
                    return nums[i];
                }
            } 
    
            return -1;
        }
    };


// 0ms

    class Solution {
        public:
            int singleNumber(vector<int>& nums) {
                int result = 0;
                for(int i=0;i<nums.size();i++){
                    result ^= nums[i];
                }
        
                return result;
            }
        };