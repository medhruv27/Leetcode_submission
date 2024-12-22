class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
      int sum=0,s=0,e=0,avg,c=0;
      int mx =INT_MIN;
      while(e<nums.size()){
         sum+= nums[e];
         int window = e-s+1;
         if(window<k){
            e++;
         }else if(window==k){
            avg = sum/k;
            if(avg>=threshold){
                c++;
            }
            sum-= nums[s];
            s++;
            e++;
         }
      }
      return c;   
    }
};