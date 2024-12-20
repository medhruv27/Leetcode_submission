class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> op;
        solve(s, op, res);
        return res;
    }
    
private:
    void solve(string ip, vector<string>& op, vector<vector<string>>& res) {
        if (ip.empty()) {
            res.push_back(op);
            return;
        }
        
        int size = ip.size();
        for (int i = 0; i < size; i++) {
            string temp = ip.substr(0, i + 1);
            if (temp == string(temp.rbegin(), temp.rend())) {
                op.push_back(temp);
                solve(ip.substr(i + 1), op, res);
                op.pop_back();
            }
        }
    }
};