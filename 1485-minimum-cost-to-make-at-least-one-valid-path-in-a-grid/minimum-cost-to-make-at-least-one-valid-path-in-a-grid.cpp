class Solution {
public:
    int m, n;

    bool isValid(int r, int c) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<pair<int, int>> directions = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        deque<pair<int, int>> dq; // Deque for 0-1 BFS
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        cost[0][0] = 0;

        dq.push_front({0, 0});

        while (!dq.empty()) {
            auto [curRow, curCol] = dq.front();
            dq.pop_front();

            for (int i = 1; i <= 4; i++) {
                int newRow = curRow + directions[i].first;
                int newCol = curCol + directions[i].second;

                if (isValid(newRow, newCol)) {
                    int newCost = cost[curRow][curCol] + (i != grid[curRow][curCol]);
                    if (newCost < cost[newRow][newCol]) {
                        cost[newRow][newCol] = newCost;
                        if (i == grid[curRow][curCol]) {
                            dq.push_front({newRow, newCol}); // No additional cost, add to the front
                        } else {
                            dq.push_back({newRow, newCol}); // Extra cost, add to the back
                        }
                    }
                }
            }
        }

        return cost[m - 1][n - 1];
    }
};
