class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        if(skill.size()%2!=0) return -1;
        if(skill.size()==2){
            return skill[0]*skill[1];
        }
        sort(skill.begin(),skill.end());
        int i=0;
        int j=skill.size()-1;
        long long prod = 0;
        vector<int> sum;
        while(i<j){
            sum.push_back(skill[i]+skill[j]);
            if(sum.size()>1){
                if(sum[i-1]!=sum[i]) return -1;
            }
            prod = prod + (skill[i]*skill[j]);
            i++;
            j--;
        }  
        return prod;      
    }
};