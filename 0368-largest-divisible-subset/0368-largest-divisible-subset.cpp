class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<int>dp(n,1);
        vector<int>hash(n,1);
        int maxi = INT_MIN;
        int last = -1;
        for(int i=0;i<n;i++){
            hash[i] =i;
            for(int prev = 0;prev<i;prev++){
                if(arr[i]%arr[prev]==0 && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
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
