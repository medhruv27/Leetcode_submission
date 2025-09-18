class Solution {
public:
    void genans(int index,int n,vector<int>&nums,set<vector<int>>&myset,vector<int>temp){
        if(index==n){
           myset.insert(temp);
        }
        for(int i=index;i<n;i++){
            swap(temp[index],temp[i]);
            genans(index+1,n,nums,myset,temp);
            swap(temp[index],temp[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       set<vector<int>>myset;
       vector<int>temp;
       temp = nums;
       sort(temp.begin(),temp.end());
        int n = nums.size();
       vector<vector<int>> result;
        genans(0,n,nums,myset,temp);
        for(auto it : myset){
            result.push_back(it);
        }
        return result;
    }
};