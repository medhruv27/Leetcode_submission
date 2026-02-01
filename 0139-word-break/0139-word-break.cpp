class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
         vector<bool> dp(s.size() + 1, false);
         dp[0] = true;
         for(int i=1;i<=s.length();i++){
            for(auto it : wordDict){
                int start = i - it.length();
                if(start>=0 && dp[start] && s.substr(start, it.length()) == it){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};