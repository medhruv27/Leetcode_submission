class Solution {
public:
    bool isPalindrome(string st) {
        int s=0;
        int e=st.length()-1;
        while(s<=e){
            if(!isalnum(st[s])){
                s++;
            }
            else if(!isalnum(st[e])){
                e--;
            }
            else{
                if(tolower(st[s])!=tolower(st[e])){
                    return false;
                }
                s++;e--;
            }
        }
        return true;
    }
};