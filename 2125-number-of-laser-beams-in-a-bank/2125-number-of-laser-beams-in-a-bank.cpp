class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        int ans = 0;
        
        for (const string& row : bank) {
            int curr = 0;
            for (char c : row) {
                if (c == '1') curr++;
            }
            if (curr > 0) {
                ans += prev * curr;  
                prev = curr;        
            }
        }
        
        return ans;
    }
};