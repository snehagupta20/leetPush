class Solution {
    public:
        bool isNStraightHand(vector<int>& hand, int groupSize) {
            if(hand.size() % groupSize != 0) return false;
    
            map<int,int> freq;
            for(int i=0;i<hand.size();i++){
                freq[hand[i]]++;
            }
    
            while(freq.size() > 0){
                int i=freq.begin()->first;
                for(int j=0;j<groupSize;j++){
                    if(!freq[i+j]) return false;
                    freq[i+j]--;
                    if(freq[i+j] < 1) freq.erase(i+j);
                }
            }
    
            return true;
        }
    };