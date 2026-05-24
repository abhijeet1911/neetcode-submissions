class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
          if(nums2.size()<nums1.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int m=nums1.size();
        int n=nums2.size();
       
        int l=0;
        int r=m;
        while(l<=r){
            int px=l+(r-l)/2;
            int py=(m+n+1)/2-px;
            int x1=(px==0)?INT_MIN:nums1[px-1];
            int x2=(py==0)?INT_MIN:nums2[py-1];
            int y1=(px==m)?INT_MAX:nums1[px];
            int y2=(py==n)?INT_MAX:nums2[py];
            if(x2<=y1 && x1<=y2){
            if((m+n)%2==0){
                return (max(x1,x2)+min(y1,y2))/2.0;

            }
            else{
                return max(x1,x2);

            }}
            if(x1>y2){
                r=px-1;
            }
            if(x2>y1) l=px+1;

        }
        return -1;
    }
};
