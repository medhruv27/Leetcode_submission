class Solution {
public:
    vector<string>res;
    void solve(int o,int e,int n,string ans){
        if(o>n || e>n) return;
        if(n==o && o==e){
            res.push_back(ans);
            return ;
        }
        solve(o + 1,e,n,ans + '(');
        if(o>e)
        solve(o,e + 1,n,ans + ')');
    }
    vector<string> generateParenthesis(int n) {
        solve(0,0,n,"");
        return res;
    }
};