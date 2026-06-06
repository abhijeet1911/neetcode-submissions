class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int max_a = 0;
        int max_b = 0;
        int max_c = 0;

        for (const auto& t : triplets) {
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) {
                continue;
            }

            max_a = max(max_a, t[0]);
            max_b = max(max_b, t[1]);
            max_c = max(max_c, t[2]);
        }

        return (max_a == target[0] &&
                max_b == target[1] &&
                max_c == target[2]);
    }
};