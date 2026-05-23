class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=speed.size();
        int fleet=0;
        double prevtime=0;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({position[i],speed[i]});

        }
        sort(v.begin(),v.end());
        for(int i=n-1;i>=0;i--){
            double curr=(double)(target-v[i].first)/v[i].second;
            if(prevtime<curr) {fleet++;
            prevtime=curr;}

        }
        return fleet;
    }
};
