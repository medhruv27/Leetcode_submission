class Solution {
public:
    int rev(int a){
        long long  ans = 0;
        while(a>0){
            int rem = a%10;
            ans = 10*ans + rem;
            a = a/10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        long long n = nums.size();
        const int MOD = 1e9 + 7;
        map<long,long>mp;
        for(int i=0;i<n;i++){
            int it  = nums[i] - rev(nums[i]);
            mp[it]++;
        }
        long long sum =0;
        for(auto it :mp){
            if(it.second>1){
                sum = (sum + it.second*(it.second-1)/2% MOD) % MOD;
            }
        }
        return sum;
    }
};
