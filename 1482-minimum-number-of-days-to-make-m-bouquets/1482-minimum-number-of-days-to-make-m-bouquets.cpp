class Solution {
public:
    int possibility(vector<int>&bloomDay,int day,int m,int k){
       int cnt =0;
       int n = bloomDay.size();
       int bloomedflwrs = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= day) {
                cnt++;
            }
            else {
                bloomedflwrs += (cnt / k);
                cnt = 0;
            }
        }
        bloomedflwrs += (cnt / k);
        return bloomedflwrs >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1ll * k * 1ll;
        int n = bloomDay.size();
        if(val>n)return -1;
        int e = *max_element(bloomDay.begin(),bloomDay.end());
        int s= *min_element(bloomDay.begin(),bloomDay.end());
        int mid;
        while(s<=e){
            mid  = (e-s)/2 + s;
            if(possibility(bloomDay,mid,m,k)==true){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return s;
    }
};