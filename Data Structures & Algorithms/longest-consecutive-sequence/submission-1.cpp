class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int longest=1;
        int cnt=0;
        int lastsmaller=INT_MIN;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]-1==lastsmaller){
                cnt+=1;
                lastsmaller=nums[i];

            }
            else if(nums[i]!=lastsmaller){
                cnt=1;
                lastsmaller=nums[i];
            }
            longest=max(cnt,longest);
        }
        return longest;
    }
};
