class Solution {
public:
    string toBase(int n, int b) {
         string res = "";
        while (n > 0) {
            int rem = n % b;
            if (rem < 10) res += char('0' + rem);
            else res += char('A' + (rem - 10));
            n /= b;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool isStrictlyPalindromic(int n) {
        bool flag = true;
        for(int b=2; b<=n-2; b++){
            string temp = toBase(n,b);
            int i = 0;
            int j = temp.size();

            while(i<j){
                if(temp[i] != temp[j]){
                    flag = false;
                    break;
                }
                else{
                    i++;j--;
                }
            }

            if(!flag) break;
        }

        return flag;
    }
};