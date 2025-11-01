class Solution {
public:
    vector<int> numOfBurgers(int ts, int cs) {
        if(2*cs>ts || ts>4*cs) return {};
        int x  = ts-2*cs;
        if(x%2!=0) return {};
        else
        return {x/2,cs - x/2};
    }
};