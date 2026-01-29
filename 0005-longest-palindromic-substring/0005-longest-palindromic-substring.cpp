class Solution {
public: 
    string bothside(string &s,int left,int right){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            left--;
            right++;
        }
        return s.substr(left + 1,right-left-1);
    }
    string longestPalindrome(string s) {
        string ans;
        for(int i=0;i<s.length();i++){
            string oddpali = bothside(s,i,i);
            string evenpali = bothside(s,i,i+1);
            if(oddpali.length()>ans.length()){
                ans = oddpali;
            }
            if(evenpali.length()>ans.length()){
                ans = evenpali;
            }
        }
        return ans;
    }
};