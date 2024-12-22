class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int s =0,e=0;
        string str = to_string(num);
        int c=0;
        while(e<str.size()){
            int window = e-s+1;
            if(window<k){
                e++;
            }else if(window==k){
                string check = str.substr(s,k);
                int divisor = stoi(check);
                if(divisor!=0 && num%divisor==0){
                    c++;
                }
                s++;
                e++;
            }
        }
        return c;
    }
};