class Solution {
public:
    int minSubArrayLen(int k, vector<int>& a) {
        int sum = 0,ans = INT_MAX,n = a.size(),s = 0,e = 0;
        while(e < n){
            sum += a[e];
            if(sum < k) e++;
            if(sum == k){
                ans = min(ans, e-s+1);
                e++;
            }
            else if(sum > k){
                while(sum >= k){
                    ans = min(ans, e-s+1);
                    sum-=a[s];
                    s++; 
                }
                e++;
            }
        }
        return ans == INT_MAX? 0 : ans;
    }
};
