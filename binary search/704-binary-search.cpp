class Solution {
public:

    int binarySearch(vector<int> nums, int target, int left, int right){
        if(left>right){
            return -1;
        }
        int midIdx=left+((right-left)/2);
        int mid = nums[midIdx];

        if(mid==target){
            return midIdx;
        }
        else if(mid>target){
            return binarySearch(nums,target,left, midIdx-1);
        }
        return binarySearch(nums,target,midIdx+1, right);

    }

    int search(vector<int>& nums, int target) {
        return binarySearch(nums,target,0,nums.size()-1);
    }
};



class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;

        while(start<=end){
            int mid = ((end-start)/2)+start;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                start = mid+1;
            }
            else if(nums[mid]>target){
                end = mid-1;
            }
        }

        return -1;
    }
};

