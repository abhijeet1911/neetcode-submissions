class Solution {
public:
bool caneat(int mid,vector<int>&piles,int h){
    int actualhrs=0;
    for(int x:piles){
        actualhrs+=x/mid;
        if(x%mid) actualhrs++;
    }
    return actualhrs<=h;
}





    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1;
        int r=*max_element(begin(piles),end(piles));
        while(l<r){
            int mid=l+(r-l)/2;
            if(caneat(mid,piles,h)){
                r=mid;
            }
            else {
                l=mid+1;
            }
        }
        return l;
    }
};
