class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      sort(intervals.begin(),intervals.end());
      int n=intervals.size();
      int cnt=0;
      vector<int>L=intervals[0];
      for(int i=1;i<n;i++){
        if(intervals[i][0]>=L[1]){
            L=intervals[i];
        }
        else if(L[1]<=intervals[i][1]){
            cnt++;
                   }
        else if(L[1]>intervals[i][1]){
            L=intervals[i];
            cnt++;        }
      }
      return cnt;
    }
};
