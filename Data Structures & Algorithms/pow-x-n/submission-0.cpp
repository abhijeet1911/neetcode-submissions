class Solution {
public:
    double myPow(double x, int n) {
        long long abs_n = n;

        if (abs_n < 0) {
            abs_n = -abs_n;
            x = 1.0 / x;
        }

        double result = 1.0;

        while (abs_n > 0) {
            if (abs_n % 2 == 1) {
                result *= x;
            }

            x *= x;
            abs_n /= 2;
        }

        return result;
    }
};
