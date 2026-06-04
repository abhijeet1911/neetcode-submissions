class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<pair<int,int>>sorted_queries;
        
        for(int i=0;i<queries.size();i++){
            sorted_queries.push_back({queries[i], i});
        }
        sort(sorted_queries.begin(), sorted_queries.end());
        sort(intervals.begin(), intervals.end());
        vector<int>result(queries.size(),-1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        int i = 0;
        int n = intervals.size();
        for (const auto& q : sorted_queries) {
            int query_val = q.first;       
            int original_idx = q.second;
            while (i < n && intervals[i][0] <= query_val) {
                int length = intervals[i][1] - intervals[i][0] + 1;
                min_heap.push({length, intervals[i][1]});
                i++; 
            }
            while (!min_heap.empty() && min_heap.top().second < query_val) {
                min_heap.pop();
            }
            if (!min_heap.empty()) {
                result[original_idx] = min_heap.top().first;
            }
        }
        return result;
    }
};
