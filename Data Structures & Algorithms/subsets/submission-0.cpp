class Solution {
public:
void getsub(vector<int>nums,vector<vector<int>>&ans,vector<int>&s,int idx,int n){
if(idx==n){
    ans.push_back(s);
    return ;
}
s.push_back(nums[idx]);
getsub(nums,ans,s,idx+1,n);
s.pop_back();
getsub(nums,ans,s,idx+1,n);







}





    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
         vector<vector<int>>ans;
         vector<int>s;
         getsub(nums,ans,s,0,n);
         return ans;
    }
};
