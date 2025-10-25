class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int t =0,c=0,ans=0;
        for (int s = 0; s < n; ++s) { 
            int sur = gas[s]-cost[s];
            t+=sur;
            c+=sur;
            if(c<0){
                c=0;
                ans = s+1;
            }
        }
        return (t>=0)?ans:-1;
    }
};