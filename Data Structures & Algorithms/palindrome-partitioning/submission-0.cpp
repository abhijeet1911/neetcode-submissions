#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current_partition;
        
        // Recursion start karte hain index 0 se
        backtrack(s, 0, current_partition, result);
        
        return result;
    }

private:
    void backtrack(const string& s, int start, vector<string>& current_partition, vector<vector<string>>& result) {
        // Base Case: Agar 'start' index string ki length ke barabar ho gaya hai,
        // toh matlab humne poori string process kar li hai.
        if (start == s.length()) {
            result.push_back(current_partition);
            return;
        }
        
        // 'start' index se lekar string ke end tak har possible tukda check karo
        for (int i = start; i < s.length(); i++) {
            
            // Check karo ki kya s[start ... i] ek palindrome hai?
            if (isPalindrome(s, start, i)) {
                
                // Agar haan, toh is tukde ko kaat kar list mein daal lo
                // s.substr(start_index, length)
                current_partition.push_back(s.substr(start, i - start + 1));
                
                // Baaki bachi aage ki string ke liye recursion call karo (i + 1 se)
                backtrack(s, i + 1, current_partition, result);
                
                // BACKTRACKING: Wapas aate waqt aakhiri tukde ko nikal do 
                // taaki loop aage badhe aur naye (bade) tukde try kar sake
                current_partition.pop_back();
            }
        }
    }
    
    // Helper function check karne ke liye ki string ka ek hissa palindrome hai ya nahi
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
