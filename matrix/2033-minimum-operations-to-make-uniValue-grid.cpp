// approach 1 :


class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            int count = 0;
    
            // pushing elements into values vector.
            vector<int> values;
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[i].size();j++){
                    values.push_back(grid[i][j]);
                }
            }
    
            sort(values.begin(), values.end());
    
            int mid = values[values.size()/2];
    
            // counting number of operations required.
            for(int i=0;i<values.size();i++){
                int num = values[i];
                if(num!=mid){
                    while(num<mid){
                        num+=x;
                        count++;
                        if(num>mid) return -1;
                    }
                    while(num>mid){
                        num-=x;
                        count++;
                        if(num<mid) return -1;
                    }
                    
                }
            }
    
            return count;
        }
    };