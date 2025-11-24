class Solution { 
public:
    bool solve(vector<int> &arr, int m,int k,int mid){
         int window = 0;
        for(int i = 0; i< arr.size(); i++){
            if(arr[i] <= mid) {
                window++;
                if(window == k) {
                    m--;
                    window = 0; // Reset window after forming a bouquet
                }
            }
            else {
                window = 0; // Break in adjacency
            }

            if(m == 0){
                return true;
            }
        }

        return false;
    }
    int minDays(vector<int>& arr, int m, int k) {
        int n = arr.size();
        long long pro = 1LL * m * k;
        if(n < pro){ // as u need to create m bouquet but also need k adjacent flowers
            return -1;
        }
        int s = *min_element(arr.begin(),arr.end());
        int e = *max_element(arr.begin(),arr.end());
        int res =e;
        while(s<=e){
            int mid = s + (e-s)/2;
            cout<<mid<<" ";
            if(solve(arr,m,k,mid)){
                res = mid;
                e = mid-1;
            }else{
                s = mid +1;
            }
        }
        return res;
    }
};