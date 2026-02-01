class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int s =0,e=0,n=nums.size();
        vector<int>ans;
        deque<int>dq;
        while(e<n){
            while(!dq.empty() && dq.back()<nums[e]){
                dq.pop_back();
            }
            dq.push_back(nums[e]);
            int ws = e-s+1;
            if(ws==k){
                ans.push_back(dq.front());
                if(nums[s]==dq.front()){
                    dq.pop_front();
                }
                s++;
            }
            e++;
        }
        return ans;
    }
};