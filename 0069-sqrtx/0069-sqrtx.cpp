class Solution {
public:
    int mySqrt(int x) {
        int s=1;
        int e=x;
       long long int i=(e-s)/2+s;
        int res;
        int ans =-1;
        if(x==0){
            return x;
        }
        while(s<=e){
           i=(e-s)/2+s;
           res = i*i;
           if(i==x/i){
               return i;
           }
           else if(i>x/i){
               e = i-1;
           }
           else{
               s=i+1;
               ans=i;
           }     
        }
        return ans;
    }
};