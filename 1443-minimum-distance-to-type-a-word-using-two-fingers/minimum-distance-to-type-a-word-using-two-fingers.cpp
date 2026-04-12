class Solution {
public:
    /**
     * Calculates the Manhattan distance between two keys on the 6-column keyboard.
     * If the finger is at the starting position (26), the cost is 0.
     */
    int dist(int a, int b) {
        if (a == 26) return 0;
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int minimumDistance(string word) {
        int n = word.size();
        
        // Priority Queue stores: {total_cost, word_index, finger1_pos, finger2_pos}
        using T = tuple<int, int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        // Visited map to store the minimum cost for a specific state
        // Key: {index, f1, f2} -> Value: min_cost
        map<tuple<int, int, int>, int> vis;

        // Initial state: index 0, both fingers hovering (represented by 26)
        pq.push({0, 0, 26, 26});

        while (!pq.empty()) {
            auto [cost, idx, f1, f2] = pq.top();
            pq.pop();

            // If we have typed all characters, return the current cost
            if (idx == n) return cost;

            // Pruning: if we found a better way to reach this state, skip
            if (vis.count({idx, f1, f2}) && vis[{idx, f1, f2}] <= cost)
                continue;
            vis[{idx, f1, f2}] = cost;

            int cur = word[idx] - 'A';

            // Option 1: Move Finger 1
            pq.push({
                cost + dist(f1, cur),
                idx + 1,
                cur,
                f2
            });

            // Option 2: Move Finger 2
            pq.push({
                cost + dist(f2, cur),
                idx + 1,
                f1,
                cur
            });
        }

        return 0;
    }
};