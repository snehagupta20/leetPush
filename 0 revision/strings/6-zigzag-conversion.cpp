class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        if(numRows >= s.size()) return s;

        string ans="";
        int firstInterval=0;

        for(int i=1;i<=numRows;i++){
            if(i==numRows){
                for(int j=i-1;j<s.size();j+=firstInterval){
                    ans+=s[j];
                }
                return ans;
            }
            int interval = (numRows-i)*2;
            int downInterval = (i-1)*2;

            if(i==1){
                firstInterval=interval;
            }

            int j = i-1;
            ans+=s[j];
            while(j<s.size()){
                //neeche 
                if(j+interval < s.size()){
                    j+=interval;
                    ans+=s[j];
                }
                else break;

                //uppar
                if(downInterval==0) continue;
                if(j+downInterval < s.size()){
                    j+=downInterval;
                    ans+=s[j];
                }
                else break;
            }
        }

        return ans;
    }
};

