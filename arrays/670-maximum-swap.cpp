class Solution {
public:
    int maximumSwap(int num) {
        string nums = to_string(num);
        for(int i=0;i<nums.size();i++){
            int first = nums[i] - '0';
            int second = 0;
            int idx = 0;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]-'0' >= second){
                    second = nums[j]-'0';
                    idx = j;
                }
            }
            if(second > first){
                swap(nums[i], nums[idx]);
                return stoi(nums);
            }   
        }
        return num;
    }
};