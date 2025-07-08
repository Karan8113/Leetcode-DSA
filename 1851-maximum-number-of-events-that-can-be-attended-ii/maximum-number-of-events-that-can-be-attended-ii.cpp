class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        // Sort events by end time
        sort(events.begin(), events.end());
        int n = events.size();
        
        // Store only end times for binary search
        vector<int> endTimes(n);
        for (int i = 0; i < n; ++i) {
            endTimes[i] = events[i][0];
        }

        // Memoization: dp[i][k] = max value from index i with k events left
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        // Sort by start time so binary search can be used
        sort(events.begin(), events.end(), [](const auto &a, const auto &b){
            return a[1] < b[1]; // sort by end time
        });

        for (int i = 0; i < n; ++i) {
            int start = events[i][0], end = events[i][1], val = events[i][2];

            // Binary search: latest event before current one
            int l = 0, r = i - 1, last = -1;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (events[m][1] < start) {
                    last = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }

            for (int j = 1; j <= k; ++j) {
                // Do not take current event
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);

                // Take current event
                int prev = last == -1 ? 0 : dp[last + 1][j - 1];
                dp[i + 1][j] = max(dp[i + 1][j], val + prev);
            }
        }

        return dp[n][k];
    }
};
