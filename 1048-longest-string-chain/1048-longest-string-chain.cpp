class Solution {
public:
    bool compare(string &s1,string &s2){
        if(s1.size()!=s2.size()+1) return false;
        int f=0,s=0;
        while(f<s1.size()){
            if(s1[f]==s2[s]){
                f++;
                s++;
            }
            else{
                f++;
            }
        }
        if(f==s1.size() && s==s2.size()){
            return true;
        }
        return false;
    }
   static bool comp(string &s1,string &s2){
        return s1.size()>s2.size();
    }
    int longestStrChain(vector<string>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end(),comp);
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int index = n-1;index>=0;index--){
            for(int prev = index-1;prev>=-1;prev--){
                    int len = 0 + dp[index+1][prev+1];
                    if(prev==-1 || compare(nums[prev],nums[index])){
                        len = max(len,1 + dp[index+1][index+1]);
                    }
                    dp[index][prev+1] = len;
            }
        }
        return dp[0][0];
    }
};