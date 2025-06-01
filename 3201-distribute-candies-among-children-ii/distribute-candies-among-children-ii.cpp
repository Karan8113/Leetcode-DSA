class Solution {
public:
    // Helper function to compute C(n + 2, 2) = (n + 2) * (n + 1) / 2
    long long C(long long x) {
        if (x < 0) return 0;
        return (x + 2) * (x + 1) / 2;
    }

    long long distributeCandies(int n, int limit) {
        long long total = C(n);

        // Subtract cases where one child exceeds limit
        total -= 3 * C(n - limit - 1);

        // Add back cases where two children exceed limit
        total += 3 * C(n - 2 * (limit + 1));

        // Subtract cases where all three children exceed limit
        total -= C(n - 3 * (limit + 1));

        return total;
    }
};

