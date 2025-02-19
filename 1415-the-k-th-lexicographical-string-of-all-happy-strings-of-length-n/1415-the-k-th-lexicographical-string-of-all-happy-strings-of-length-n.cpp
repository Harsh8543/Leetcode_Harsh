class Solution {
public:
void generateHappyStrings(int n, string curr, vector<string> &happyStrings, char lastChar) {
    if (curr.size() == n) {
        happyStrings.push_back(curr);
        return;
    }
    
    for (char ch : {'a', 'b', 'c'}) {
        if (ch != lastChar) {  // Ensure no consecutive characters are the same
            generateHappyStrings(n, curr + ch, happyStrings, ch);
        }
    }
}
    string getHappyString(int n, int k) {
        vector<string> happyStrings;
    generateHappyStrings(n, "", happyStrings, '\0');

    return (k <= happyStrings.size()) ? happyStrings[k - 1] : "";
    }
};