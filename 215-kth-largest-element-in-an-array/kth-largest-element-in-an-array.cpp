class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
                priority_queue<int> heap(nums.begin(), nums.end());
                        while (--k) heap.pop();
                                return heap.top();
        }
}; 

        




// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int, vector<int>, greater<int>> pq;  // min heap

//         for (int num : nums) {
//             pq.push(num);
//             if (pq.size() > k) pq.pop();
//         }

//         return pq.top();
//     }
// };