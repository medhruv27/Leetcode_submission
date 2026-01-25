class Solution {
public:
    int numSquares(int n){
        if (n <= 0){
            return 0;
        }
        vector<int> cnt(n + 1, INT_MAX);
        cnt[0] = 0;
        for (int i = 1; i <= n; i++){
            // For each i, it must be the sum of some number (i - j*j) and 
            // a perfect square number (j*j).
            for (int j = 1; j*j <= i; j++){
                cnt[i] = min(cnt[i], cnt[i - j*j] + 1);
            }
        }
        return cnt.back();
    }
};