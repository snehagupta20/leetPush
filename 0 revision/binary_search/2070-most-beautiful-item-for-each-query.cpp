class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());

        // setting max till now in items
        int maxb = items[0][1];
        for(int i=0;i<items.size();i++){
            maxb = max(maxb, items[i][1]);
            items[i][1] = maxb;
        }

        // finding through binary search
        vector<int> result;
        for(int i=0;i<queries.size();i++){

            int l = 0;
            int r = items.size()-1;
            int mid = 0;
            int ans = 0;

            while(l<=r){
                mid = l + (r-l)/2;
                if(items[mid][0] > queries[i]){
                    r=mid-1;
                } else {
                    ans=max(ans, items[mid][1]);
                    l=mid+1;
                }
            }
            result.push_back(ans);
        }
        return result;
    }
};


/*
[136,746,0][176,746,1][193,746,2][210,799,3][247,919,4][395,919,5][478,919,6][487,919,7][533,919,8][542,946,9][567,946,10][640,946,11][701,946,12][749,946,13][763,946,14][781,962,15][864,962,16][914,962,17][958,962,18]

[885,1445,1580,1309,205,1788,1214,1404,572,1170,989,265,153,151,1479,1180,875,276,1584]
*/


/*
THIRD TRY SOL

// - find items <= queries[i]
// - store max beauty
// - return vec

// i think ki, is items vector mei se, jitne bhi mutliple items hai, un sabko hata do, just keep that one jiske paaas max beauty ho.
// - traverse. if i==i+1, remove i

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());

        // removing duplicates from items 
        int i=0;
        while(i<items.size()-1){
            if(items[i][0]==items[i+1][0]){
                items.erase(items.begin()+i);
            }
            else{
                i++;
            }
        }

        // setting max till now in items
        int maxb = items[0][1];
        for(int i=0;i<items.size();i++){
            maxb = max(maxb, items[i][1]);
            items[i][1] = maxb;
        }

        // filling in results vector
        vector<int> result;
        for(i=0;i<queries.size();i++){
            int j=0;
            int ans=0;
            while(j<items.size() && queries[i]>=items[j][0]){
                ans = max(ans,items[j][1]);
                j++;
            }
            result.push_back(ans);
        }

        return result;

    }
};
*/





/*

class Solution {
public:

    int customBinarySearch(vector<vector<int>>& items, int queryPrice) {
        int l = 0;
        int r = items.size()-1;

        int mid;
        int maxBeauty = 0;

        while(l <= r) {
            mid = l + (r-l)/2;

            if(items[mid][0] > queryPrice) {
                r = mid-1; //ignore current and right side items. Move to left now.
            } else {
                maxBeauty = max(maxBeauty, items[mid][1]);
                l = mid+1;
            }
        }

        return maxBeauty;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        int m = queries.size();

        vector<int> result(m);

        //step-1 : Sort the array based on price in asencind order
        sort(begin(items), end(items)); //{pricei, beautyi}

        int maxBeautySeen = items[0][1];
        for(int i = 1; i < n; i++) {
            maxBeautySeen = max(maxBeautySeen, items[i][1]);
            items[i][1] = maxBeautySeen;
        }


        for(int i = 0; i < m; i++) {
            int queryPrice = queries[i];
            result[i] = customBinarySearch(items, queryPrice);
        }

        return result;

    }
};

*/