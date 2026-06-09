#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Edge case: Agar input khali hai, toh empty array return karo
        if (digits.empty()) {
            return {};
        }
        
        vector<string> result;
        string current_combo = "";
        
        // Keypad ki mapping array ke through (Index 2 par "abc", Index 3 par "def"...)
        // Index 0 aur 1 khali rahenge kyunki phone mein unpar koi letters nahi hote
        vector<string> pad = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        // Recursion index 0 se shuru karenge
        backtrack(digits, 0, current_combo, result, pad);
        
        return result;
    }

private:
    void backtrack(const string& digits, int index, string& current_combo, vector<string>& result, const vector<string>& pad) {
        
        // Base Case: Agar humne saare digits process kar liye hain
        if (index == digits.length()) {
            result.push_back(current_combo); // Pura combination save kar lo
            return;
        }
        
        // Current digit kya hai, wo nikalte hain (e.g., '2' se integer 2)
        int current_digit = digits[index] - '0';
        
        // Us digit par kaunse letters available hain (e.g., "abc")
        string letters = pad[current_digit];
        
        // Har letter ke liye ek naya rasta try karte hain
        for (char letter : letters) {
            
            // Choice: Take It (Letter ko string mein add karo)
            current_combo.push_back(letter);
            
            // Agle digit (index + 1) ke liye recursion call karo
            backtrack(digits, index + 1, current_combo, result, pad);
            
            // Backtracking: Choice ko undo karo taaki loop mein agla letter try ho sake
            current_combo.pop_back();
        }
    }
};