class Solution {
public:
    int minimizedMaximum(int n, vector<int>& q) {
        int low = 1;
        int high = *max_element(q.begin(), q.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long c = 0;
            for (int x : q) {
                c += (x + mid - 1) / mid;
                if (c > n) break;
            }

            if (c <= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};