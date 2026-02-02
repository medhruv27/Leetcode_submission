class Solution {
public:
    string solve(string &s,int& i){
        string res ="";
        int n = 0;
        while(i<s.size()){
            char c = s[i];
            if(isdigit(c)){
                n = n*10 + (c-'0');
                i++;
            }else if(c == '['){
                i++;
                string recstr = solve(s,i);
                for(int x =0;x<n;x++){
                    res += recstr;
                }
                n = 0;
            }else if(c == ']'){
                i++;
                return res;
            }else{
                res+=c;
                i++;
            }
        }
        return res;
    }
    string decodeString(string s) {
        int i =0;
        return solve(s,i);
    }
};