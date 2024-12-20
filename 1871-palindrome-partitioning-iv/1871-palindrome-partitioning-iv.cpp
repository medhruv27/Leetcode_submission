class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        while (i < j){
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    bool solve(string &s, int i, int partitions, int n){
        if (i >= n) return partitions==0;
        if (partitions==0) return isPalindrome(s,i,n-1);

        bool check=false;
        for (int k=i;k<n-1;k++){
            if (isPalindrome(s,i,k)){
                check=check || solve(s,k+1,partitions-1,n);
            }
        }
        return check;
    }
    bool checkPartitioning(string s) {
        int i=0;
        int n=s.size();
        return solve(s,i,2,n); 

    }
};