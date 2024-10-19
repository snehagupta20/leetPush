class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int n) {
        int size = hand.size();
        if(size % n != 0) return false;

        map<int,int> freq;

        for(int i=0;i<hand.size();i++){
            freq[hand[i]]++;
        }


        while(!freq.empty()){
            int i = freq.begin()->first;
            for(int j=0;j<n;j++){
                // next consecutive element is not present.
                if(freq[i+j] == 0) {
                    return false;
                }

                freq[i+j]--;

                if(freq[i+j]<1){
                    freq.erase(i+j);
                }
            }
        }

        return true;
    }
};