class Solution {
public:
    const int MOD = 1337;

    int power(int a, int n) {
        if (n == 0)
            return 1;

        a %= MOD;

        if (n % 2 == 0)
            return power((1LL * a * a) % MOD, n / 2);

        return (1LL * a * power((1LL * a * a) % MOD, n / 2)) % MOD;
    }

    int superPow(int a, vector<int>& b) {
        if (b.empty())
            return 1;

        int lastDigit = b.back();
        b.pop_back();

        int part1 = power(superPow(a, b), 10);
        int part2 = power(a, lastDigit);

        return (1LL * part1 * part2) % MOD;
    }
};