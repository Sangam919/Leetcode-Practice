class Solution {
public:
    void backtrack(int i, int target, vector<int>& candidates,
                   vector<int>& curr, vector<vector<int>>& res) {
        
        // Base case: found a valid combination
        if (target == 0) {
            res.push_back(curr);
            return;
        }

        // Base case: no more candidates or target < 0
        if (i == candidates.size() || target < 0) {
            return;
        }

        // Option 1: include candidates[i]
        curr.push_back(candidates[i]);
        backtrack(i, target - candidates[i], candidates, curr, res);  
        curr.pop_back();

        // Option 2: skip candidates[i]
        backtrack(i + 1, target, candidates, curr, res);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(0, target, candidates, curr, res);
        return res;
    }
};
