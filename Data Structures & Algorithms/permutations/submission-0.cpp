class Solution {
public:
void helper(vector<int>nums,vector<vector<int>>&ans,int n,int idx){
     if(idx==n){
        ans.push_back(nums);
        return ;
     }
        for(int i=idx;i<n;i++){
            swap(nums[i],nums[idx]);
            helper(nums,ans,n,idx+1);
            swap(nums[i],nums[idx]);
            
            

        }
}
  vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        helper(nums,ans,n,0);
        return ans;
    }
};
