// Approach 1 : Brute-force
// TC is O(n), SC is O(1) or O(n) (depends on recursive/iterative approach)

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n < 0) return 1 / myPow(x, -n);
        return x * myPow(x, n - 1);
    }
};

// Approach 2.1 : Binary Exponentiation (Recursive)
// TC is O(logn), SC is O(logn)

class Solution {
public:
    double binaryExp(double x, long long n) {
        if (n == 0) return 1;
        if (n < 0) return 1.0 / binaryExp(x, -1 * n);

        if (n % 2 == 1) return x * binaryExp(x * x, (n - 1) / 2);
        return binaryExp(x * x, n / 2);
    }

    double myPow(double x, int n) {
        return binaryExp(x, (long long) n);
    }
};

// Approach 2.2 : Binary Exponentiation (Iterative)
// TC is O(logn), SC is O(1)

class Solution {
public:
    double binaryExp(double x, long long n) {
        if (n == 0) return 1;
        if (n < 0) {
            n = -1 * n;
            x = 1 / x;
        }

        double res = 1;
        while (n) {
            if (n % 2 == 1) {
                res *= x;
                n -= 1;
            }
            x *= x;
            n /= 2;
        }
        return res;
    }

    double myPow(double x, int n) {
        return binaryExp(x, (long long) n);
    }
};