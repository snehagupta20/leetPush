class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int min = 0;
        int freshOranges = 0;

        // counting fresh oranges & marking pos of rotten oranges
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    freshOranges++;
                }
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty() && freshOranges > 0){
            int size = q.size();
            for(int k=0;k<size;k++){
                pair<int,int> p = q.front();
                q.pop();
                int i = p.first;
                int j = p.second;

                // up
                if(i+1<grid.size() && grid[i+1][j]==1){
                    freshOranges--;
                    q.push({i+1,j});
                    grid[i+1][j]=2;
                }

                // down
                if(i-1>=0 && grid[i-1][j]==1){
                    freshOranges--;
                    q.push({i-1,j});
                    grid[i-1][j]=2;
                }

                // right
                if(j+1<grid[i].size() && grid[i][j+1]==1){
                    freshOranges--;
                    q.push({i,j+1});
                    grid[i][j+1]=2;
                }

                // left
                if(j-1>=0 && grid[i][j-1]==1){
                    freshOranges--;
                    q.push({i,j-1});
                    grid[i][j-1]=2;
                }
            }  
            min++;
        }

        return freshOranges == 0 ? min : -1;
    }
};