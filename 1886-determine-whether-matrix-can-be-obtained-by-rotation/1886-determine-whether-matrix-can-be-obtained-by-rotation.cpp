class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        for(int r=0;r<n;r++){
            for(int c=0;c<r;c++){
                swap(matrix[r][c],matrix[c][r]);
            }
        }
        for(int r=0;r<n;r++){
            for(int c=0;c<n/2;c++){
                swap(matrix[r][c],matrix[r][n-1-c]);
            }
        }
        return matrix;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i=0;i<4;i++){
            if(mat==target) return true;
            else rotate(mat);
        }
        return false;
    }
};