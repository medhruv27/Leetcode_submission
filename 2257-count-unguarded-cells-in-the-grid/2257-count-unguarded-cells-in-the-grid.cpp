class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& g, vector<vector<int>>& w) {
        vector<vector<int>>ans(m,vector<int>(n,0));
        for(int i=0;i<w.size();i++){
            ans[w[i][0]][w[i][1]] = 2;
        }
        long cnt=0;
        for(int i=0;i<g.size();i++){
            int r = g[i][0];
            int c = g[i][1];
            ans[r][c] = -1;
            for(int i=r;i<m;i++){
                if(ans[i][c]==2 || (ans[i][c] == -1 && i!=r) ){
                    break;
                }else if(ans[i][c] == 0){
                    ans[i][c] = 1;
                    cnt++;
                }
            }
            for(int i=r;i>=0;i--){
                if(ans[i][c]==2 || (ans[i][c] == -1 && i!=r)){
                    break;
                }else if(ans[i][c] == 0){
                    ans[i][c] = 1;
                    cnt++;
                }
            }
            for(int j=c;j<n;j++){
                if(ans[r][j]==2 || (ans[r][j] == -1 && j!=c)){
                    break;
                }else if(ans[r][j] == 0){
                    ans[r][j] = 1;
                    cnt++;
                }
            }
            for(int j=c;j>=0;j--){
                if(ans[r][j]==2 || (ans[r][j] == -1 && j!=c)){
                    break;
                }else if(ans[r][j] == 0){
                    ans[r][j] = 1;
                    cnt++;
                }
            }
        }
        // long c= 0;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(ans[i][j]==0){
        //             c++;
        //         }
        //     }
        // }
        int res = (m*n) - (cnt + g.size()+w.size());
        return (res>0)?res:0;
    }
};