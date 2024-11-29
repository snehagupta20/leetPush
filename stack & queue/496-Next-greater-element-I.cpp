class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> ans(nums1.size());

        for(int i=0;i<nums2.size();i++){
            while(!st.empty() && nums2[i]>nums2[st.top()]){
                auto it = find(nums1.begin(), nums1.end(), nums2[st.top()]);
                if(it!=nums1.end()) ans[distance(nums1.begin(), it)] = nums2[i];
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            auto it = find(nums1.begin(), nums1.end(), nums2[st.top()]);
            if(it!=nums1.end()) ans[distance(nums1.begin(), it)] = -1;
            st.pop();
        }

        return ans;
    }
};