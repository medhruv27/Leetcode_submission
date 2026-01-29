class Solution {
public:
    int dp[1001][1001];
    int maxi =0,indx=-1;
    string solve(int n,int m,string &s,string &t){
        for(int i=0;i<=n;i++){
            dp[i][0] =0;
            dp[0][i] =0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    // if(maxi<dp[i][j]){
                    //     maxi = dp[i][j];
                    //     indx = i-1;
                    // }
                    if (maxi < dp[i][j]) {
                        if (i - dp[i][j] == n - j) {
                            maxi = dp[i][j];
                            indx = i - 1;
                        }
                    }
                }else{
                    dp[i][j] =0;
                }
            }
        }
        cout<<maxi<<" "<<indx;
        return s.substr(indx-maxi+1,maxi);
    }
    string longestPalindrome(string s) {
        string t = s ;
        int n = s.length();
        int m = n;
        reverse(t.begin(),t.end());
        memset(dp,-1,sizeof(dp));
        return solve(n,m,s,t);
    }
};