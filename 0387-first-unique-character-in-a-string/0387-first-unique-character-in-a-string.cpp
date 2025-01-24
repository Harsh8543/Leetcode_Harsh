class Solution {
public:
    int firstUniqChar(string s) {
            unordered_map<char, int> char_count;
    for (char c : s) {
        char_count[c]++;
    }
    for (int i = 0; i < s.size(); i++) {
        if (char_count[s[i]] == 1) {
            return i;
        }
    }
    return -1;
    }
};