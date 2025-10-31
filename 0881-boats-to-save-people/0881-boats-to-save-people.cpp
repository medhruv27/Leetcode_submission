class Solution {
public:
    int numRescueBoats(vector<int>& p, int l) {
        sort(p.begin(),p.end());
        int c=0,s=0,e=p.size()-1;
        while(s<e){
            int sum =p[s]+p[e];
            if(sum<=l){
                c++;
                s++;
                e--;
            }else if(sum>l){
                e--;c++;
            }
        }
        if(s==e) c++;
        return c;
    }
};