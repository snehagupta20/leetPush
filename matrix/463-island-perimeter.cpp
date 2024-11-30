class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for(int j=0;j<grid.size();j++){
            for(int i=0; i<grid[0].size();i++){
                if(grid[j][i] == 1){
                    //top
                    if(j-1 < 0 || grid[j-1][i] == 0) perimeter++;

                    //bottom
                    if(j+1 >= grid.size() || grid[j+1][i] == 0) perimeter++;

                    //left
                    if(i-1 < 0 || grid[j][i-1] == 0) perimeter++;

                    //right
                    if(i+1 >= grid[0].size() || grid[j][i+1] == 0) perimeter++;
                }
            }
        }

        return perimeter;
    }
};


/*
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    perimeter += 4;
                    if (r > 0 && grid[r-1][c] == 1) {
                        perimeter -= 2;
                    }
                    if (c > 0 && grid[r][c-1] == 1) {
                        perimeter -= 2;
                    }
                }
            }
        }
        
        return perimeter;
    }
};

*/