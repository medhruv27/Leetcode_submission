class Solution {
public:
    int possible(vector<int>&weights,int cap){
        int load =0;
        int days =1;
        for(int i=0;i<weights.size();i++){
            if(weights[i] + load > cap){
                load = weights[i];
                days++;
            }
            else{
                load+= weights[i];
            }
        }
        return days;
    } 
    int shipWithinDays(vector<int>& weights, int days) {
        int s = *max_element(weights.begin(),weights.end());
        int e = accumulate(weights.begin(),weights.end(),0);
        while(s<=e){
            int mid = (e-s)/2 +s;
            int noofdays = possible(weights,mid);
            if(noofdays<=days){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return s;
    }
};