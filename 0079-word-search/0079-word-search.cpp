class Solution {
public:
    bool solve(int i,int j,int r,int c,string word,vector<vector<char>>&g,int a){
        int n = word.size();
        if(a==n-1){
            return word[a]==g[i][j];
        }
        char gg = g[i][j];
        g[i][j] ='1';
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        for(int k=0;k<4;k++){
            int nr = i + drow[k];
            int nc = j + dcol[k];
            if(nr>=0 && nc>=0 && nr<r && nc<c && g[nr][nc]==word[a+1]){
               if(solve(nr,nc,r,c,word,g,a+1)) return true;
            }
        }
        g[i][j] =gg;
        return false;
    }
    bool exist(vector<vector<char>>& g, string word) {
        int r = g.size();
        int c = g[0].size();
        string temp = "";
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(word[0]==g[i][j]){
                    if(solve(i,j,r,c,word,g,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};