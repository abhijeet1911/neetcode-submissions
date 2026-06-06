class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        for(int i=0;i<n;i++){
            if(cost[i]>gas[i]) continue;
            int j=(i+1)%n;
            int currgas=gas[i]-cost[i]+gas[j];
            while(j!=i){
                if(currgas<cost[j]) break;
              int gasfrommovingthisj=cost[j];
              j=(j+1)%n;
              int newgas=gas[j];
              currgas=currgas-gasfrommovingthisj+newgas;
            }
            if(i==j) return i;
        }
        return -1;
    }
};
