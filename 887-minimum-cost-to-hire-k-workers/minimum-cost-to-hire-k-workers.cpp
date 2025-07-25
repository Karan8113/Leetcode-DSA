class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers; // {ratio, quality}
        
        for (int i = 0; i < n; i++) {
            double ratio = (double)wage[i] / quality[i];
            workers.push_back({ratio, quality[i]});
        }

        sort(workers.begin(), workers.end());

        priority_queue<int> pq; // max-heap
        int total_quality = 0;
        double min_cost = DBL_MAX;

        for (auto [ratio, q] : workers) {
            pq.push(q);
            total_quality += q;

            if (pq.size() > k) {
                total_quality -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                min_cost = min(min_cost, total_quality * ratio);
            }
        }

        return min_cost;
    }
};
