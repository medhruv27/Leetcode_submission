class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        vector<vector<int>> ans;
        int n1 = f.size(), n2 = s.size();
        int i, j;
        for (i = 0, j = 0; i < n1 && j < n2;) {
            if (f[i][0] == s[j][0]) { // Equal start times
                if (f[i][1] == s[j][1]) {
                    ans.push_back({f[i][0], s[j][1]});
                    i++; j++;
                } else if (f[i][1] > s[j][1]) {
                    ans.push_back({f[i][0], s[j][1]});
                    j++;
                } else {
                    ans.push_back({f[i][0], f[i][1]});
                    i++;
                }
            } else if (f[i][0] < s[j][0]) { // First interval starts earlier
                if (f[i][1] >= s[j][0]) { // Check for overlap
                    if (f[i][1] == s[j][1]) {
                        ans.push_back({s[j][0], s[j][1]});
                        i++; j++;
                    } else if (f[i][1] > s[j][1]) {
                        ans.push_back({s[j][0], s[j][1]});
                        j++;
                    } else {
                        ans.push_back({s[j][0], f[i][1]});
                        i++;
                    }
                } else { // No overlap
                    i++;
                }
            } else if (f[i][0] > s[j][0]) { // Second interval starts earlier
                if (s[j][1] >= f[i][0]) { // Check for overlap
                    if (f[i][1] == s[j][1]) {
                        ans.push_back({f[i][0], s[j][1]});
                        i++; j++;
                    } else if (f[i][1] > s[j][1]) {
                        ans.push_back({f[i][0], s[j][1]});
                        j++;
                    } else {
                        ans.push_back({f[i][0], f[i][1]});
                        i++;
                    }
                } else { // No overlap
                    j++;
                }
            }
        }
        return ans;
    }
};