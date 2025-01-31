class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows >= s.size() || numRows==1){
            return s;
        }

        string ans = "";

        for(int i=1;i<=numRows;i++){

            int upInterval = (i-1)*2;               // important
            int downInterval = (numRows-i)*2;       // important 

            if(i==numRows){
                for(int k=i-1;k<s.size();k+=upInterval){
                    ans+=s[k];
                }
                break;
            }

            ans+=s[i-1];

            int j=i-1;
            while(j<s.size()){
                // down
                if(j+downInterval < s.size()){
                    j+=downInterval;
                    ans+=s[j];
                }
                else break;

                // up
                if(upInterval==0) continue;
                if(j+upInterval < s.size()){
                    j+=upInterval;
                    ans+=s[j];
                }
                else break;
            }
        }

        return ans;
    }
};