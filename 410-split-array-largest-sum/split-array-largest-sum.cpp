class Solution {
public:
    bool checkValid(int minSum, int &k, vector<int> &nums) {
        int sum = 0;
        int totSub = 1;

        for(int num: nums) {
            sum += num;
            if(sum > minSum) {
                totSub++;
                sum = num;
            }
            if(totSub > k) return false;
        }

        return totSub <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        int start = 0;
        int end = 0;
        int ans = 0;

        for(int i=0; i<n; i++) {
            start = max(start, nums[i]);
            end += nums[i];
        }

        while(start <= end) {
            int mid = start + (end - start)/2;

            if(checkValid(mid, k, nums)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};