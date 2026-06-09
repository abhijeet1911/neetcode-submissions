class Solution {
public:
   set<vector<int>>s;
    void solve(vector<int>& candidates, int idx, int target,
               vector<int>& curr, vector<vector<int>>& ans) {

        if(target == 0) {
            if(s.find(curr)==s.end()){
            ans.push_back(curr);
            s.insert(curr);
            return;}
        }

        if(idx == candidates.size() || target < 0) {
            return;
        }

        curr.push_back(candidates[idx]);

        solve(candidates, idx+1, target - candidates[idx],
              curr, ans);
              
        solve(candidates, idx, target - candidates[idx],
              curr, ans);

        curr.pop_back();

        solve(candidates, idx + 1, target,
              curr, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target) {

        vector<vector<int>> ans;
        vector<int> curr;

        solve(candidates, 0, target, curr, ans);

        return ans;
    }
};