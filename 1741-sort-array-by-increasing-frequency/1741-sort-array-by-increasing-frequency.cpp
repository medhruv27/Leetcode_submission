class Solution {
public:
    class Compare{
        public:
        bool operator()(pair<int,int>&a, pair<int,int>&b){
            if(a.first == b.first){
                return a.second<b.second;
            }
            return a.first>b.first;
        }
    };
    vector<int> frequencySort(vector<int>& nums) {
       unordered_map<int,int>mpp;
        for(int i =0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare>minh;
        for(auto it:mpp){
            minh.push({it.second, it.first});
        }
        vector<int>ans;
        while(!minh.empty()){
            int freq = minh.top().first;
            int ele = minh.top().second;
            for(int i =0;i<freq;i++){
                ans.push_back(ele);
            }
            minh.pop();
        }
        return ans; 
    }
};