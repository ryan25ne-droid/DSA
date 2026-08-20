# define ll long long
class Solution {
public:
    const int MOD = 1e9 + 7;

// Fast modular exponentiation: (base^exp) % MOD
    ll power(ll base, ll exp) {
        ll res = 1;
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
    ll modInverse(ll n) {
        return power(n, MOD - 2);
    }

// Compute n! % MOD 
    ll factorial(int n) {
        ll res = 1;
        for (int i = 1; i <= n; i++) {
            res = (res * i) % MOD;
        }
        return res;
    }

// Compute nCk % MOD 
    ll comb(int n, int k) {
        if (k < 0 || k > n) return 0;
        ll num = factorial(n);            
        ll den = (factorial(k) * factorial(n - k)) % MOD; 

        return (num * modInverse(den)) % MOD;
    }

    ll countValidSequences(int n, int k) {
        if (k > n) return 0;

// Total ways
        ll total = comb(n - 1, k - 1);

// Subtract cases where each group size is odd
        ll odd = 0;
        if ((n - k) % 2 == 0) {
            int m = (n - k) / 2;
            odd = comb(m + k - 1, k - 1);
        }

        return (total - odd + MOD) % MOD;
    }
};
