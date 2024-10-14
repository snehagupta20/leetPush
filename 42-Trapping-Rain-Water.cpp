class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();

        vector<int> leftmax(size);
        leftmax[0] = height[0];
        for(int i=1;i<size;i++){
            leftmax[i] = max(leftmax[i-1], height[i]);
        }

        vector<int> rightmax(size);
        rightmax[size-1] = height[size-1];
        for(int i=size-2;i>=0;i--){
            rightmax[i] = max(rightmax[i+1], height[i]);
        }

        int ans = 0;
        for(int i=0;i<height.size();i++){
            ans += min(leftmax[i], rightmax[i]) - height[i];
        }
        return ans;
    }
};

// ans += min(leftmax, rightmax) - height