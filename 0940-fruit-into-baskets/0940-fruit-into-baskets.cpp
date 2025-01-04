class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left =0,right =0,n= fruits.size(),maxi =INT_MIN;
        unordered_map<int,int>mp;
        while(right<n){
            mp[fruits[right]]++;
            
            if(mp.size()>2){
               mp[fruits[left]]--;
                if(mp[fruits[left]]==0){
                    mp.erase(fruits[left]);
                }
                left++;
            }
            int windowsize = right-left+1;
            maxi = max(maxi,windowsize);right++;
        }
        return maxi;
    }
};