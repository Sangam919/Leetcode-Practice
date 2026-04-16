class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        
        // store indices of each value
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<int> ans;
        
        for(int q : queries) {
            int val = nums[q];
            vector<int>& v = mp[val];
            
            // if only one occurrence
            if(v.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            
            // find position using lower_bound
            int idx = lower_bound(v.begin(), v.end(), q) - v.begin();
            
            int prev = v[(idx - 1 + v.size()) % v.size()];
            int next = v[(idx + 1) % v.size()];
            
            int d1 = min(abs(q - prev), n - abs(q - prev));
            int d2 = min(abs(q - next), n - abs(q - next));
            
            ans.push_back(min(d1, d2));
        }
        
        return ans;
    }
};