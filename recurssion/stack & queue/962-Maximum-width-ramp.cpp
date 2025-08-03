class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        for(int i=0;i<nums.size();i++){
            if(st.empty() || nums[st.top()]>nums[i]) st.push(i);
        }

        int ans=INT_MIN;
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                ans=max(ans,(i-st.top()));
                st.pop();
            }
        }
        return ans;
        
    }
};



/*
    int i=0;
    int j=nums.size()-1;
    int ans=0;

    while(i<nums.size()){

        int diff=0;

        if(nums[i]>nums[j]) j--;

        else if(nums[i]<=nums[j]){
            diff=j-i;
            ans=max(ans,diff);
            i++;
            j=nums.size()-1;
            continue;
        }

        if(j==i){
            i++;
            j=nums.size()-1;
        }
    }
    return ans;
*/