class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int min = ceil((double)b.size() / a.size());
        
        string repeatedA = "";
        for(int i=1;i<=min;i++){
            repeatedA += a;
        }
        if(repeatedA.find(b) != string::npos) return min;

        repeatedA += a;
        if(repeatedA.find(b) != string::npos) return min+1;

        return -1;
    }
};

