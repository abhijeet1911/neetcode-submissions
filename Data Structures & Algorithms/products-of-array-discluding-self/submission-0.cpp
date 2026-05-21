class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int cnt=0;
       int n=nums.size();
       int product=1;
       int productwithoutzero=1;
       for(int i=0;i<n;i++){
        if(nums[i]==0) cnt++;
        else{
            productwithoutzero*=nums[i];
        }
        product*=nums[i];

       }
       vector<int>result(n);
       for(int i=0;i<n;i++){
         if(cnt==0){
            result[i]=product/nums[i];
         }
         else if(cnt==1){
            if(nums[i]==0) result[i]=productwithoutzero;
            else result[i]=product/nums[i];
         }
         else{
            result[i]=0;
         }
       }
       return result;
    }
};
