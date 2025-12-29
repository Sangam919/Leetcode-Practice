class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {

        // step 1: sort by second value
        sort(pairs.begin(), pairs.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        int ans = 1;                 // pehla pair le liya
        int last = pairs[0][1];      // last pair ka end

        // step 2: check next pairs
        for (int i = 1; i < pairs.size(); i++) {
            if (pairs[i][0] > last) {
                ans++;
                last = pairs[i][1];
            }
        }

        return ans;
    }
};
