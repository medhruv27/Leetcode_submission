class Solution {
public:
    vector<int> mostCompetitive(vector<int>& num, int k) {
        k = num.size()-k;
        if (num.size() == k) return {0};
        stack<int>s;
        for(int c : num){
            while(!s.empty() && s.top()>c && k>0){
               s.pop();
               k--;
            }
            s.push(c);
        }
        while (k > 0 && !s.empty()) {
            s.pop();
            k--;
        }
        vector<int>temp;
        while(!s.empty()){
            temp.push_back(s.top());
            s.pop();
        }
        reverse(temp.begin(),temp.end());
        // while (temp.size() > 1 && temp[0] == 0) {
        //     temp.erase(temp.begin());
        // }
        return temp;
    }
};