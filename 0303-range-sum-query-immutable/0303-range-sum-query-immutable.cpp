class NumArray {
public:
  vector<int>nums;
    NumArray(vector<int>& nums) {
        long long sum=0;
        this->nums.push_back(sum);
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            this->nums.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        return nums[right+1]-nums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */