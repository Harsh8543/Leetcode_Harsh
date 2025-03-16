class Solution {
public:
    vector<string> letterCombinations(string digits) {
         if (digits.empty()) {
            return {};
        }
        vector<string> digit_to_char = {
            "",    "",    "abc",  "def", "ghi", 
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        vector<string> result;
        string current_combination;

        function<void(int)> backtrack = [&](int index) {
            if (index == digits.size()) {
                result.push_back(current_combination);
                return;
            }
            string letters = digit_to_char[digits[index] - '0'];
            for (char letter : letters) {
                current_combination.push_back(letter);
                current_combination.pop_back();
            }
        };
        backtrack(0);
        return result;
    }
};