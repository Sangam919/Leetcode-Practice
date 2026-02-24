class Solution {
public:
    bool ispossible(vector<int>& position, int& m, int& d) {
        int last = position[0];
        int reduceballs = 1;
        for (int i = 1; i < position.size(); i++) {
            if ((position[i] - last) >= d) {
                reduceballs++;
                last = position[i];
            }
            if (reduceballs >= m) {
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int low = 1;
        int high = position[n - 1];
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (ispossible(position, m, mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};