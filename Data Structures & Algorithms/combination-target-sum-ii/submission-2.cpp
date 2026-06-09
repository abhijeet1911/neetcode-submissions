#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current_comb;

        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0, current_comb, result);

        return result;
    }

private:
    void backtrack(vector<int>& candidates, int target, int start_index,
                   vector<int>& current_comb,
                   vector<vector<int>>& result) {

        if (target == 0) {
            result.push_back(current_comb);
            return;
        }

        for (int i = start_index; i < candidates.size(); i++) {

            if (i > start_index &&
                candidates[i] == candidates[i - 1]) {
                continue;
            }

            if (candidates[i] > target) {
                break;
            }

            current_comb.push_back(candidates[i]);

            backtrack(candidates,
                      target - candidates[i],
                      i + 1,
                      current_comb,
                      result);

            current_comb.pop_back();
        }
    }
};