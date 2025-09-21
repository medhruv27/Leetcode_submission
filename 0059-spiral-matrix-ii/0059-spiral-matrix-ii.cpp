class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top =0 , bottom = n-1,left =0,right = n-1;
        int c =1 , t = n*n;
        vector<vector<int>>res(n,vector<int>(n,0));
        while(c<=t){
            for(int i=left;i<=right && c<=t;i++){
                res[top][i] = c;
                c++;
            }
            top++;
            for(int i=top;i<=bottom && c<=t;i++){
                res[i][right] = c;
                c++;
            }
            right--;
            for(int i=right;i>=left && c<=t;i--){
                res[bottom][i] = c;
                c++;
            }
            bottom--;
            for(int i=bottom;i>=top && c<=t;i--){
                res[i][left] = c;
                c++;
            }
            left++;
        }
        return res;

    }
};