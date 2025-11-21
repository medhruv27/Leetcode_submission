class Solution {
public:
    int maxProfit(vector<int>& p) {
        int mini = p[0];
        int ans=0;
        for(int i=1;i<p.size();i++){
            if(p[i]>mini){
                ans+= p[i]-mini;
            }
                mini = p[i];
            
        }
        return ans;
    }
};