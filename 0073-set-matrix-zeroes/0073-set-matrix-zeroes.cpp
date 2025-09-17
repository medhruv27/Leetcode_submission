class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int f = 0;
        int colside =0;
        int rowside =0;
        for(int i=1;i<r;i++){
             if(matrix[i][0]==0){
                colside=1;
             }
        }
        for(int j=1;j<c;j++){
             if(matrix[0][j]==0){
                rowside=1;
             }
        }
        if(matrix[0][0]==0){
            colside=1;
            rowside=1;
        }
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                if(matrix[i][j]==0){
                     matrix[0][j] =0;
                     matrix[i][0] =0;
                }
            }
        }
        for(int i=1;i<r;i++){
            if(matrix[i][0]==0){
                for(int j=0;j<c;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int j=1;j<c;j++){
            if(matrix[0][j]==0){
                for(int i=0;i<r;i++){
                    matrix[i][j]=0;
                }
            }
        }
        if(colside==1){
            for(int i=0;i<r;i++){
                matrix[i][0] =0;
            }
        }
        if(rowside==1){
            for(int j=0;j<c;j++){
                matrix[0][j] =0;
            }
        }
    }
};