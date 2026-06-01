class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq(stones.begin(),stones.end());
        while(!pq.empty()&&pq.size()>1){
            int maxi1=pq.top();
            pq.pop();
            int maxi2=pq.top();
            pq.pop();
            if(maxi1!=maxi2){
             pq.push(abs(maxi1-maxi2));
            }
        }
        return pq.size()==1?pq.top():0;
    }
};
