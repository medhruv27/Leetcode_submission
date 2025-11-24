class Solution {
public:
    bool solve(vector<int> &arr, int k,int mid){
        int c =0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=mid){
                c++;
            }else{
                int r = ceil((double)arr[i]/mid);
                c+=r;  
            }
            if(c>k) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& arr, int h) {
        int n = arr.size();
        int s = 1;
        int e = *max_element(arr.begin(),arr.end());
        sort(arr.begin(),arr.end());
        int res =-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            cout<<mid;
            if(solve(arr,h,mid)){
                res = mid;
                e = mid-1;
            }else{
                s = mid +1;
            }
        }
        return res;
    }
};