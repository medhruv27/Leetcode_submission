class Solution {
public:
    int res = 0;

    bool ispali(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void solve(int i, int n, string& s) {
        if (i == n) {
            return;
        }
        for (int j = i; j < n; j++) {
            if (ispali(s, i, j)) {
                res++;
            }
        }
        solve(i + 1, n, s);
    }

    int countSubstrings(string s) {
        int n = s.length();
        solve(0, n, s);
        return res;
    }
};
