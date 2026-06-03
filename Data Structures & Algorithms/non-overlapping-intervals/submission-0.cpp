class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int i=0;
        int j=1;
        int cnt=0;
        int n=intervals.size();
        while(j<n){
            vector<int>curr=intervals[i];
            vector<int>next=intervals[j];
            int cs=curr[0];
            int ce=curr[1];
            int ns=next[0];
            int ne=next[1];
            if(ce<=ns){
                i=j;
                j++;
            }
            else if(ce<=ne){
                cnt++;
                j++;
            }
            else if(ce>ne){
                i=j;
                j++;
                cnt++;
            }
        }
        return cnt;
    }
};
