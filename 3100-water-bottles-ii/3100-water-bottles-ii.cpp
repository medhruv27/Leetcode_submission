class Solution {
public:
    int maxBottlesDrunk(int b, int e) {
        int ans=b,r=0;
        while(true){
            if(b-e>=0){
                r++;
                b =b-e;
                e++;
            }
            else{
                b =r +b;
                if(r==0) return ans;
                ans +=r;
                r=0;
            }
        }
        return ans;
    }
};