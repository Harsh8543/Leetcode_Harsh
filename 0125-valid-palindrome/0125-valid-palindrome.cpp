class Solution {
public:
bool isAlphanumeric(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}
char toLowercase(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A'); 
    }
    return c;
}
    bool isPalindrome(string s) {
           int l = 0, r = s.size() - 1;

    while (l< r) {
        while (l< r && !isAlphanumeric(s[l])) {
            l++;
        }
        while (l < r && !isAlphanumeric(s[r])) {
            r--;
        }
        if (toLowercase(s[l]) != toLowercase(s[r])) {
            return false;
        }
        l++;
        r--;
    }
    return true;
    }
};