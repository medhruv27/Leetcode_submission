class Solution {
public:
    string solve(string& s,int& i){
        int n =0;
        string res ="";
        while(i<s.length()){
            char c = s[i];
            if(isdigit(c)){
                n = n*10 + (c-'0');
                cout<<n<<endl;
                i++;
            }else if(c == '['){
                i++;
                string recstr = solve(s,i);
                cout<<recstr<<endl;
                for(int x=0;x<n;x++){
                    res += recstr;
                }
                n=0;
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