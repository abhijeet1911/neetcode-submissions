

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        backtrack(result, "", 0, 0, n);

        return result;
    }

private:
    void backtrack(vector<string>& result, string current_string,
                   int open_count, int close_count, int n) {

        if (current_string.length() == n * 2) {
            result.push_back(current_string);
            return;
        }

        if (open_count < n) {
            backtrack(result, current_string + "(",
                      open_count + 1, close_count, n);
        }

        if (close_count < open_count) {
            backtrack(result, current_string + ")",
                      open_count, close_count + 1, n);
        }
    }
};