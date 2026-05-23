class Solution {
public:
    int find_pivot(vector<int> &nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r]){
               l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return r;
    }
int binarysearch(int l,int r,vector<int>arr,int target){
    while(l<=r){
        int mid=l+(r-l)/2;
        if(target<arr[mid]){
            r=mid-1;
        }
        else if(target>arr[mid]) l=mid+1;
        else return mid;
    }
    return -1;
}








    int search(vector<int>& nums, int target) {
        int n= nums.size();
        int pivot_index=find_pivot(nums);
        int idx=binarysearch(0,pivot_index-1,nums,target);
            if(idx!=-1) return idx;
        
        idx=binarysearch(pivot_index,n-1,nums,target);
        return idx;


    }

};
