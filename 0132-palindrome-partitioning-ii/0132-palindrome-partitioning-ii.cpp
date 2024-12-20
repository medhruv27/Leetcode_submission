class Solution {
public:
bool isPalin(string &str,int i,int j){
    int s = i;
    int e = j;
    while(s<=e){
        if(str[s] != str[e]){
           return false;
        }
        s++;
        e--;
    }
    return true;
}
int solve(string &s,int i,int j,vector<vector<int>> &dp){
    if(i>=j) return 0;
    if(isPalin(s,i,j) == true) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mn = INT_MAX;
    for(int k = i;k<j;k++){
        if(isPalin(s,i,k) == true) {
        int temp =  solve(s,k+1,j,dp) + 1;
        
        mn = min(mn,temp);
        }
    }
    return dp[i][j] = mn;
}

    int minCut(string s) {
        vector<vector<int>> dp(2001,vector<int>(2001,-1));
        return solve(s,0,s.size()-1,dp);
    }
};