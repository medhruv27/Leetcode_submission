class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int total = (n+m);
        if(n>m) return findMedianSortedArrays(nums2,nums1);
        int left = (total+1)/2;
        int s =0,e =n,l1=0,l2=0,r1=n,r2=m;
        while(s<=e){
            int m1= (s+e)>>1;
            int m2 = left-m1;
            int l1=(m1<=0)?INT_MIN:nums1[m1-1];
            int l2=(m2<=0)?INT_MIN:nums2[m2-1];
            int r1=(m1>=n)?INT_MAX:nums1[m1];
            int r2=(m2>=m)?INT_MAX:nums2[m2];
            if(l1<=r2 && l2<=r1){
                if(total%2==1){
                    return (double)max(l1,l2);
                }
                else{
                    return ((double)max(l1,l2) + (double)min(r1,r2))/2.0;
                }
            }
            else if(l1>r2){
               e=m1-1;
            }else{
                s = m1+1;
            }

        }
        return 0;
    }
};