class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1};
        int l=0;
        int r=nums.size()-1;
        int mid =0;

        while(l<=r){
            mid = l + (r-l)/2;
            if(nums[mid] == target){
                cout<<"found target "<<mid<<endl;
                int l=mid, r=mid;
                while(l>=0 && nums[l]==target){
                    l--;
                }
                while(r<nums.size() && nums[r] == target){
                    r++;
                }
                ans[0] = l+1;
                ans[1] = r-1;
                return ans;
            }
            else if(nums[mid]>target){
                cout<<"mid > target"<<endl;
                r=mid-1;
            }
            else if(nums[mid]<target){
                cout<<"mid < target"<<endl;
                l=mid+1;
            }
        }

        return ans;
    }
};

// - find element through binary search
// - if not found, return [-1,-1]
// - if found, l-- and r-- till u get some other number
// return start & end index




























/*
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        if(nums.size()==0){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int low=0;
        int high=nums.size()-1;
        int mid=0;
        

        while(low<=high){
            mid=low+((high-low)/2);

            if(nums[mid] == target){
                low=mid;
                high=mid;
                while(low>=0 && nums[low]==target){
                    low--;
                }
                low++;
                ans.push_back(low);

                while(high<nums.size() && nums[high]==target){
                    high++;
                }
                high--;
                ans.push_back(high);

                return ans;
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

        if(ans.size()==0){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};
*/