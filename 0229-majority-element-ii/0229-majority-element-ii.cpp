class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(); 
        int el1= INT_MIN;
        int el2= INT_MIN;
        int c1=0,c2=0;
        for(int i=0;i<n;i++){
          if(c1==0 && el2!=nums[i]){
              c1++;
              el1=nums[i];
          }
          else if(c2==0 && el1!=nums[i]){
              c2++;
              el2=nums[i];
          }
          else if(el1 == nums[i]){
              c1++;
          }
          else if(el2 == nums[i]){
              c2++;
          }
          else{
              c1--;
              c2--;
          }
        }
        c1=0;
        c2=0;
        for(int i=0;i<n;i++){
            if(el1==nums[i]){
                c1++;
            }
            else if(el2==nums[i]){
                c2++;
            }
        }
        vector<int>ans;
        int mini = int(n / 3) + 1;
    if (c1 >= mini) ans.push_back(el1);
    if (c2 >= mini) ans.push_back(el2);

        return ans;
    }
};