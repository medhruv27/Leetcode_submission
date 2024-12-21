class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int>mp;
        int n = deck.size();
        for(int i=0;i<n;i++){
            mp[deck[i]]++;
        }
       int result = mp[deck[0]];
    for (int i = 1; i < deck.size(); ++i) {
        result = gcd(result, mp[deck[i]]);  
    }
        return result>1;
    }
};