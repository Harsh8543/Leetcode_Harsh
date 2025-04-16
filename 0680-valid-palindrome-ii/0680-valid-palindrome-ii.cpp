// class Solution {
// public:
//     bool validPalindrome(string s) {
//         int cnt=0;
//         int i=0;
//         int j=s.length()-1;
//         while(i<=j){
//             if(s[i]==s[j]){
//                 i++;
//                 j--;
//             }
//             else{
//                 cnt++;
//                 i++;
//             }
        
//             if(cnt>1){
//                 return false;
//             }
//         }
//         if(cnt==0 || cnt==1){
//             return true;
//         }
//      return false;
        
//     }
// };
class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        while (i <= j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        while (i <= j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                // Try skipping either the left or the right character
                return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
            }
        }
        return true;
    }
};
