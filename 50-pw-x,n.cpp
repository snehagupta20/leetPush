class Solution {
public:
    double myPow(double x, int n) {
        // Handle the base case where n is zero
        if (n == 0) return 1;
        
        // Convert n to long long to avoid overflow when n == INT_MIN
        long long N = n;
        
        // Handle negative exponents
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        // Recursive call
        return powHelper(x, N);
    }
    
    // Recursive helper function
    double powHelper(double x, long long n) {
        if (n == 0) return 1;  // Base case
        if (n == 1) return x;  // Base case

        // If n is even, use the relation x^n = (x^(n/2))^2
        if (n % 2 == 0) {
            double half = powHelper(x, n / 2);
            return half * half;
        } else { // If n is odd, use the relation x^n = x * x^(n-1)
            return x * powHelper(x, n - 1);
        }
    }
};
