// class Solution {
// public:
//     double myPow(double x, int n) {
//         long long N = n; // Use long long to handle edge case like n = INT_MIN
//         if (N < 0) {
//             x = 1 / x;
//             N = -N;
//         }
//         double result = 1.0;
//         while (N > 0) {
//             if (N % 2 == 1) {
//                 result *= x;
//             }
//             x *= x;
//             N /= 2;
//         }
//         return result;
//     }
// };
class Solution {
public:
    double myPow(double x, int n) {
        // Convert n to long long to avoid overflow for INT_MIN
        long long N = n;
        if (N < 0) {
            x = 1 / x;    // Negative exponent: x^-n = 1 / x^n
            N = -N;
        }
        return fastPow(x, N);
    }
    
    double fastPow(double x, long long n) {
        if (n == 0) {
            return 1;     // Base case: anything^0 = 1
        }
        double half = fastPow(x, n / 2);  // Recursively compute x^(n/2)
        if (n % 2 == 0) {
            return half * half;           // If n is even: x^n = (x^(n/2))^2
        } else {
            return half * half * x;       // If n is odd:  x^n = (x^(n/2))^2 * x
        }
    }
};
