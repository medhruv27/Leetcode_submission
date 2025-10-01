class Solution {
public:
    int maxBottlesDrunk(int b, int e) {
        int ans=b,r=0;
        while(true){
            // int r = 1;
            int b2 = b-e;
            if(b2>=0){
                r++;
                b =b2;
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