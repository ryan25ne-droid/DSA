class Solution {
public:
    const int MOD = 1e9 + 7;

    // Fast modular exponentiation: (base^exp) % MOD
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    // Modular inverse using Fermat's Little Theorem
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

    // Compute n! % MOD directly
    long long factorial(int n) {
        long long res = 1;
        for (int i = 1; i <= n; i++) {
            res = (res * i) % MOD;
        }
        return res;
    }

    // Compute nCk % MOD without precomputation
    long long comb(int n, int k) {
        if (k < 0 || k > n) return 0;
        long long num = factorial(n);              // n!
        long long den = (factorial(k) * factorial(n - k)) % MOD; // k! * (n-k)!
        return (num * modInverse(den)) % MOD;
    }

    long long countValidSequences(int n, int k) {
        if (k > n) return 0;

        // Total ways: stars and bars with xi >= 1
        long long total = comb(n - 1, k - 1);

        // Subtract cases where each group size is odd
        long long odd = 0;
        if ((n - k) % 2 == 0) {
            int m = (n - k) / 2;
            odd = comb(m + k - 1, k - 1);
        }

        return (total - odd + MOD) % MOD;
    }
};
