class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> result = {{}};
    
            for(int num : nums){
                int size = result.size();
                for(int i=0;i<size;i++){
                    vector<int> set = result[i];
                    set.push_back(num);
                    result.push_back(set);
                }
            }
    
            return result;
        }
    };

// solution is mind blowing.