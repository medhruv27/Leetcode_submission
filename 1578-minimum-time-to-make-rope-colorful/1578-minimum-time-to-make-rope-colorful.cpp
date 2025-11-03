class Solution {
public:
    int minCost(string c, vector<int>& t) {
        int n = c.size();
        int maxi = 0;    
        int resmax = 0;   
        for (int i = 0; i < n; ++i) {
            maxi = t[i];
            while (i + 1 < n && c[i] == c[i + 1]) {
                ++i;                      
                maxi = max(maxi, t[i]); 
            }
            resmax += maxi;
        }
        int total = accumulate(t.begin(), t.end(), 0);
        return total - resmax;
    }
};