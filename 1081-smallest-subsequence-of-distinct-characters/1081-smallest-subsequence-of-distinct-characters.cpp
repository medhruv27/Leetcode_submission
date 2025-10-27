class Solution {
public:
    string smallestSubsequence(string s) {
        vector<bool>seen(26,false);
        vector<int>lastidx(26,0);
        int n = s.size();
        for(int i=0;i<n;i++){
            lastidx[s[i]-'a'] = i; 
        }
        stack<char>st;
        for(int i=0;i<n;i++){
            if(seen[s[i]-'a']){
                continue;
            } 
            while(st.size()>0 && st.top()>s[i] && i < lastidx[st.top()-'a']){
                seen[st.top()-'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            seen[s[i]-'a'] = true;
        }
        string ans ="";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};