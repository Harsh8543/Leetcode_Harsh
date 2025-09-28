// class Solution {
// public:
//     vector<int> decimalRepresentation(int n) {
    //     vector<int>har;
    //     while(n){
    //         int mult=1;
    //         int m=n%10;
    //         int t=n/10;
    //         int ans=m*mult;
    //    har.push_back(ans);
    //         mult*=10;
    //         return the t to the net iteration of the while loop
    //     }
    //     reverse(har.begin(),har.end());

     class Solution {
public:
     vector<int> decimalRepresentation(int n) {
        vector<int> har;
        long long mult = 1;  
        while (n) {
            int m = n % 10;
            int t = n / 10;
            long long ans = 1LL * m * mult;
            if (ans != 0) {
                har.push_back((int)ans); 
            }
            mult *= 10;
            n = t;
        }
        reverse(har.begin(), har.end());
        return har;
    }
};

//     }
// };