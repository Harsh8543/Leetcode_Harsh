class Solution {
    public:
    bool isPalindrome(string &s,int start,int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++,end--;
        }
        return true;
    }
   string longestPalindrome(string s) {
 int l=s.length();
        string ans="";
        for(int i=0;i<l;i++){
            for(int j=i;j<l;j++){
                if(isPalindrome(s,i,j)){
                    string t=s.substr(i,j-i+1);
                    ans=t.size()>ans.size()?t:ans;
                }
            }
        }
        return ans;
    }
 
};