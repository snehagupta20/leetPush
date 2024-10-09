
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int size=piles.size();
        if(h==size){
            return piles[size-1];
        }
        int low=1;
        int high=piles[size-1];
        while(low<=high){
            int  mid = low + ((high-low)/2);
            cout<<\mid = \<<mid<<endl;
            long long sum=0;
            for(int j=0;j<piles.size();j++){
                sum+=ceil((double)piles[j] / mid);
            }
            cout<<\sum = \<<sum<<endl;
            if(sum<=h && high==mid){
                cout<<\sum<=h && high==mid\<<endl;
                return mid;
            }
            if(sum<=h){
                cout<<\sum<=h\<<endl;
                high = mid;
            }
            else if(sum>h){
                cout<<\sum>h\<<endl;
                low=mid+1;
            }
        }

        return 0;
    }
};


