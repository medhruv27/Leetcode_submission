class Solution {
public:
     void solve(string s,string op,vector<string>&m){
        if(s.size()==0){
            m.push_back(op);
            return;
        }
        string op1 =op;
        string op2 =op;
        if(isdigit(s[0])){
            op1.push_back(s[0]);
            op2.push_back(s[0]);
        }
        else{
            op1.push_back(tolower(s[0]));
            op2.push_back(toupper(s[0]));
        }
        s.erase(s.begin()+0);
        solve(s,op1,m);
        solve(s,op2,m);
    }
    vector<string> letterCasePermutation(string s) {
        string op;
        vector<string>m;
        solve(s,op,m);
        set<string>mset(m.begin(),m.end());
        vector<string>mf(mset.begin(),mset.end());
        return mf;
    }
};