class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<int> dp(n,1);
        vector<int> hash(n,1);
        for(int index=0;index<=n-1;index++){
             hash[index] =index;
            for(int prev=0;prev<=index-1;prev++){
                if(arr[index]%arr[prev]==0 && 1+dp[prev] >dp[index]){
                    dp[index] = 1 + dp[prev];
                    hash[index] = prev;
                }
            }
        }
        int ans= -1;
        int last =-1;
        for(int i=0;i<n;i++) {
            if(dp[i]>ans){
                ans = dp[i];
                last = i;
            }
        }
        vector<int>temp;
        temp.push_back(arr[last]);
        while(hash[last]!=last){
            last = hash[last];
            temp.push_back(arr[last]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};