class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int result=n;
        int l=0;
        int r=n-1;
        while(l<=r){
        int mid=l+(r-l)/2;
        if(nums[mid]>mid){
            r=mid-1;
            result=mid;
        }
        else{
            l=mid+1;
            
        }
        }
        return result;
    }
};
