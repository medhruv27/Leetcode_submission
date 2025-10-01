class Solution {
public:
    int numWaterBottles(int b, int e) {
        int ans=b;
        while(b>=e){
            int r = b%e;
            int d = b/e;
            ans+=d;
            b = r+d;

        }
        return ans;
    }
};