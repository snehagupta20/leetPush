class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size()-1;
            int leftidx=-1;
            while(left<=right){
                int mid = left+(right-left)/2;
                if(nums[mid]<=target){
                    leftidx = mid;
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
            if(leftidx==-1) return 0;
            else if(nums[leftidx]==target){
                return leftidx;
            } 
            return leftidx+1;
        }
    };

/*
class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int low = 0;
            int high = nums.size()-1;
            int mid = 0;
    
            while(low<=high){
                mid = low + ((high-low)/2);
                cout<<nums[mid]<<endl;
    
                if(nums[mid] == target){
                    return mid;
                }
                else if(nums[mid] > target){
                    high = mid;
                    high--;
                }
                else if(nums[mid] < target){
                    low = mid;
                    low++;
                }
            }
    
            return low;
        }
    };

*/
    
    
    
    // class Solution {
    // public:
    //     int binarySearch (vector<int> nums, int target, int start, int end){
    //         if(start>end){
    //             return 0;
    //         }
    //         int midIdx = start + ((end-start)/2);
    //         cout<<"mididx = "<<midIdx<<endl;
    //         int mid = nums[midIdx];
    //         cout<<"mid = "<<mid<<endl;
    
    //         if(mid == target){
    //             cout<<"mid == target"<<endl;
    //             return midIdx;
    //         }
    
    //         else if(mid >  target){
    //             cout<<"i shpould be here"<<endl;
    //             if(midIdx-1>=start && nums[midIdx-1] == target ){
    //                 cout<<nums[midIdx-1]<< "<="<< target<<endl; 
    //                 return midIdx-1;    
    //             }
    //             else if(midIdx-1>=start && (nums[midIdx-1] < target) ){
    //                 cout<<nums[midIdx-1]<< "<="<< target<<endl; 
    //                 return midIdx;    
    //             }
    //             else{
    //                 cout<<"mid > target"<<endl;
    //                 return binarySearch(nums, target, start, midIdx-1);
    //             }
    //         }
    //         else if( midIdx+1<=end && nums[midIdx+1] >= target ){
    //             cout<< nums[midIdx+1]<<" >="<< target<<endl;
    //             return midIdx+1;
    //         }
            
    //         else{
    //             cout<<"mid<target"<<endl;
    //             return binarySearch(nums,target,midIdx+1,end);
    //         }
            
    //     }
    //     int searchInsert(vector<int>& nums, int target) {
    //         if(target > nums[nums.size()-1]){
    //             return nums.size();
    //         }
    //         if(target <= nums[0]){
    //             return 0;
    //         }
    //         return binarySearch(nums, target, 0, nums.size()-1);
    //     }
    // };