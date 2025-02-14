class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> freq;

        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto f:freq){
            pq.push({f.second, f.first});
        }

        while(k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;
    }
};

/*
class Solution {
public:
    struct compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            if(a.second == b.second){
                return a.first > b.first;
            }
            return a.second < b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
        map<int,int> freq;

        for(auto i : nums){
            freq[i]++;
        }

        for(auto i : freq){
            pq.push(i);
        }

        vector<int> ans;
        while(k>0){
            ans.push_back(pq.top().first);
            pq.pop();
            k--;
        }

        return ans;
    }
};

*/