

class Solution {
public:
    int divide(int a, int b) {
   int sign = 1;
        if(a == INT_MIN && b == -1)return INT_MAX;
        if(a < 0 ^ b < 0) sign = -1;
        long long n = abs((long long)a);
        long long d = abs((long long)b);
        return sign*(n/d);
    }
};