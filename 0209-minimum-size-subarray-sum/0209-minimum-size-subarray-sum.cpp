class Solution {
public:
    int minSubArrayLen(int k, vector<int>& a) {
        int sum = 0;
        int ans = INT_MAX;
        int n = a.size();
        int i = 0;
        int j = 0;
        while(j < n){
            sum += a[j];
            if(sum < k) j++;
            else{
                while(sum >= k){
                    ans = min(ans,j-i+1);
                    sum-=a[i];
                    i++; 
                }
                j++;
            }
        }

        return ans == INT_MAX? 0 : ans;
    }
};
