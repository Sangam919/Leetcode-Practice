class Solution {
public:
    int countWalls(vector<int>& walls, long long l, long long r) {
        if (l > r) return 0;
        return upper_bound(walls.begin(), walls.end(), r) - 
               lower_bound(walls.begin(), walls.end(), l);
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();

        vector<pair<int,int>> a;
        for(int i = 0; i < n; i++){
            a.push_back({robots[i], distance[i]});
        }

        sort(a.begin(), a.end());
        sort(walls.begin(), walls.end());

        vector<int> left(n), right(n), overlap(n, 0);

        // compute left/right destruction
        for(int i = 0; i < n; i++){
            long long pos = a[i].first;
            long long d = a[i].second;

            long long L = pos - d;
            long long R = pos + d;

            if(i > 0) L = max(L, (long long)a[i-1].first + 1);
            if(i < n-1) R = min(R, (long long)a[i+1].first - 1);

            left[i] = countWalls(walls, L, pos);
            right[i] = countWalls(walls, pos, R);
        }

        // compute overlap
        for(int i = 0; i < n-1; i++){
            long long pos1 = a[i].first, d1 = a[i].second;
            long long pos2 = a[i+1].first, d2 = a[i+1].second;

            long long rightEnd = min(pos1 + d1, pos2 - 1LL);
            long long leftStart = max(pos2 - d2, pos1 + 1LL);

            long long L = max(pos1, leftStart);
            long long R = min(rightEnd, pos2);

            overlap[i] = countWalls(walls, L, R);
        }

        // DP
        vector<vector<long long>> dp(n, vector<long long>(2, 0));

        dp[0][0] = left[0];
        dp[0][1] = right[0];

        for(int i = 1; i < n; i++){
            dp[i][0] = left[i] + max(dp[i-1][0], dp[i-1][1] - overlap[i-1]);
            dp[i][1] = right[i] + max(dp[i-1][0], dp[i-1][1]);
        }

        return max(dp[n-1][0], dp[n-1][1]);
    }
};