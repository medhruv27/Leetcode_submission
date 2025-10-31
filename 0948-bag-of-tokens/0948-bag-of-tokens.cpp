class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int p) {
        sort(t.begin(),t.end());
        int s=0,e=t.size()-1,c=0;
        while(s<e){
            if(c==0 || t[s]<=p){ //faceup
                if(t[s]<=p){
                    p-=t[s];
                    c++;
                    cout<<c<<"faceup"<<p<<endl;
                }
                s++;
            }else if(p<t[s] && c>=1){
                p += t[e];
                c--;
                e--;
                cout<<c<<"facedown"<<p<<endl;
            }
        }
        if(s==e){
            if(t[s]<=p)c++;
        }
        return c;
    }
};