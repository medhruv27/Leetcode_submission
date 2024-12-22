class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum =0;
        double mx= INT_MIN;
        double avg =0;
        int s =0;
        int e=0;
        while(e<nums.size()){
            sum+= nums[e];
            int window = e-s+1;
            if(window<k){
                e++;
            }else if(window==k){
                avg = sum/k;
                mx = max(avg,mx);
                sum-=nums[s];
                s++;
                e++;
            }
            
        }
        return mx;
    }
};