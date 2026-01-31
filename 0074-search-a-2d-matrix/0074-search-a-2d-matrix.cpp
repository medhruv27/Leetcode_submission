class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start =0;
        int row = matrix.size();
        int col = matrix[0].size();
        int end = row*col-1;
        int mid = start + (end-start)/2;
        while(start<=end){
        if(target==matrix[mid/col][mid%col]){
            return 1;
        }
          if(target<matrix[mid/col][mid%col]){
              end =mid-1;
        }
          if(target>matrix[mid/col][mid%col]){
             start =mid+1;
        }
         mid = start + (end-start)/2;

        }
        
        return 0;
    }
};