class Solution {
public:
    long long minMoves(vector<int>& b) {
        int n = b.size();
        long long total = 0;
        for (int x : b) total += (long long)x;
        if (total < 0) return -1;
        int negIdx = -1;
        long long remaining = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] < 0) {
                negIdx = i;
                remaining = - (long long)b[i];
                break;
            }
        }
        if (remaining == 0) return 0;
        long long moves = 0;
        for (int i=1;i<=n/2 && remaining > 0;i++) {
            int l = (negIdx - i + n) % n;
            int r = (negIdx + i) % n;
            long long available = 0;
            if (l != r) {
                available += (long long)b[l];
                available += (long long)b[r];
            } else {
                available += (long long)b[l];
            }
            if (available >= remaining) {
                moves += remaining * i;
                remaining = 0;
            } else {
                moves += available * i;
                remaining -= available;
            }
        }
        return moves;
    }
};