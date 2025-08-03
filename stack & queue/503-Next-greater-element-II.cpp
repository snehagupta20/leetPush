class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int size=nums.size();
        vector<int> ans(size);

        // doubling the vector
        for(int i=0;i<size-1;i++){
            nums.push_back(nums[i]);
        }

        // finding nge
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                if(st.top()<size) ans[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }

        // rest elements of stack pushing in arr
        while(!st.empty()){
            if(st.top()<size) ans[st.top()] = -1;
            st.pop();
        }

        return ans;
    }
};