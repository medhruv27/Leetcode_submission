class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& num1, vector<int>& num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        stack<int> st;
        unordered_map<int , int > mp;
        for(int i = n2-1 ;i >= 0 ;i--){
            if(st.empty()){
                mp[num2[i]] = -1;
            }
            else if(st.top( ) > num2[i]){
                mp[num2[i]] = st.top();
            }
            else{
                while(!st.empty() and st.top() <= num2[i]){
                    st.pop();
                }
                if(st.size() == 0) mp[num2[i]] = -1;
                else mp[num2[i]]  = st.top();
            }
            st.push(num2[i]);
        }
        vector<int> res;
        for(auto &x : num1){
            res.push_back(mp[x]);
        }
        return res;
    }
};