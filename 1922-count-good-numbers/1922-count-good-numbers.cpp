class Solution {
public:
    static const long long MOD = 1000000007;

    int power(long long a, long long b){
        if(b == 0) return 1;

        if(b % 2 == 0){
            return power((long long) a*a % MOD, b/2);
        }

        return a * power((long long) a*a % MOD, b/2) % MOD;
    }

    int countGoodNumbers(long long n) {
        long long even_count = (n+1)/2;
        long long odd_count = n/2;

        return (long long) power(5, (n+1)/2) * power(4, n/2) % MOD;
    }
};