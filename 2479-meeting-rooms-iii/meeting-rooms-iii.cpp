class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        
        // Min-heap for busy rooms: {end_time, room_index}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;
        
        // Min-heap for idle rooms: room_index
        priority_queue<int, vector<int>, greater<>> idle;
        for (int i = 0; i < n; ++i) {
            idle.push(i);
        }
        
        vector<int> count(n, 0); // meeting count per room
        
        for (auto& meeting : meetings) {
            long long start = meeting[0], end = meeting[1];
            long long duration = end - start;
            
            // Free up rooms whose meeting is done before current start time
            while (!busy.empty() && busy.top().first <= start) {
                idle.push(busy.top().second);
                busy.pop();
            }
            
            int room;
            if (!idle.empty()) {
                room = idle.top();
                idle.pop();
                busy.push({start + duration, room});
            } else {
                // All rooms busy → wait for the one that finishes earliest
                auto [end_time, rid] = busy.top();
                busy.pop();
                busy.push({end_time + duration, rid});
                room = rid;
            }
            
            count[room]++;
        }
        
        // Find the room with the highest meeting count (smallest index if tie)
        int maxCount = 0, result = 0;
        for (int i = 0; i < n; ++i) {
            if (count[i] > maxCount) {
                maxCount = count[i];
                result = i;
            }
        }
        return result;
    }
};
