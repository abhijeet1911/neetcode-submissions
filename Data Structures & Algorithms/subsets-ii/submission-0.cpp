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
int i=idx+1;
while(i<n && nums[i]==nums[i-1]){
    i++;
}
getsub(nums,ans,s,i,n);

}
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
         vector<vector<int>>ans;
         vector<int>s;
         getsub(nums,ans,s,0,n);
         return ans;
    }
};
