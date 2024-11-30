class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        // transpose the matrix
        for(int j=0;j<matrix.size();j++){
            for(int i=j+1;i<matrix.size();i++){
                swap(matrix[j][i], matrix[i][j]);
            }
        }

        // reverse each row
        for(int j=0;j<matrix.size();j++){
            reverse(matrix[j].begin(), matrix[j].end());
        }

        return;
    }
};



/*
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> ans=matrix;
        int k=0;
        for(int i=matrix.size()-1;i>=0;i--){
            for(int j=0;j<matrix[0].size();j++){
                matrix[j][k]=ans[i][j];
            }
            k++;
        }
        return;
    }
};
*/