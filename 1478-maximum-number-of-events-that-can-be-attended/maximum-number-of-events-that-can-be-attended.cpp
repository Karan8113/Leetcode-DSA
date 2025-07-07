class Solution {
public:
    int findParent(vector<int>& parent, int u) {
        if (parent[u] == u) return u;
        return parent[u] = findParent(parent, parent[u]);
    }

    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1]; // sort by earliest end time
        });

        int maxDay = 0;
        for (auto& e : events) maxDay = max(maxDay, e[1]);

        vector<int> parent(maxDay + 2);
        for (int i = 0; i <= maxDay + 1; i++) {
            parent[i] = i;
        }

        int count = 0;
        for (auto& it : events) {
            int start = it[0];
            int end = it[1];

            // Find the earliest available day ≥ start
            int availDay = findParent(parent, start);
            if (availDay <= end) {
                count++;
                // Mark this day as used by linking to next day
                parent[availDay] = findParent(parent, availDay + 1);
            }
        }

        return count;
    }
};
