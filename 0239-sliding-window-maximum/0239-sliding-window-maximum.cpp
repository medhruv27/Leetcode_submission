class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int s=0,e=0;
        vector<int>ans;
        deque<int>dq;
        while(e<nums.size()){
          while(!dq.empty() && nums[e]>dq.back()){
            dq.pop_back();
          } 
          dq.push_back(nums[e]);
          int windowsize = e-s+1;
          if(windowsize<k){
            e++;
          }
          else if(windowsize==k){
            ans.push_back(dq.front());
            if(nums[s]==dq.front()){
                dq.pop_front();
            }
            s++;
            e++;
          }
        }
        return ans;
    }
};