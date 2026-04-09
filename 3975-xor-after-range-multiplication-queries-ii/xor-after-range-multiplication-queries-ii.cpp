class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long get_inverse(long long val) {
        long long res = 1, exp = MOD - 2;
        val %= MOD;
        while (exp) {
            if (exp & 1) res = res * val % MOD;
            val = val * val % MOD;
            exp >>= 1;
        }
        return res;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int n = nums.size();
        const int threshold = sqrt(n);

        int small_q_count = 0;
        for (int i = 0; i < queries.size(); ++i) {
            const int L = queries[i][0], R = queries[i][1], step = queries[i][2], val = queries[i][3];
            if (step >= threshold) {
                for (int j = L; j <= R; j += step) {
                    nums[j] = (long long)nums[j] * val % MOD;
                }
            } else {
                if (small_q_count != i) queries[small_q_count] = std::move(queries[i]);
                small_q_count++;
            }
        }
        queries.resize(small_q_count);

        sort(queries.begin(), queries.end(), [](const vector<int>& a, const vector<int>& b) {
            uint64_t keyA = ((uint64_t)a[2] << 40) | ((uint64_t)(a[0] % a[2]) << 20) | (uint32_t)a[0];
            uint64_t keyB = ((uint64_t)b[2] << 40) | ((uint64_t)(b[0] % b[2]) << 20) | (uint32_t)b[0];
            return keyA < keyB;
        });

        queries.push_back({0, 0, -1, 0}); 
        auto group_end = queries.begin();

        while ((*group_end)[2] != -1) {
            const auto group_start = group_end;
            const int step = (*group_start)[2];
            const int offset = (*group_start)[0] % step;
            // Find the first query that belongs to a different group
             group_end = find_if(group_start, queries.end(), [step, offset](const auto& q) {
                return q[2] != step || (q[0] % step) != offset;
            });
            
            // --- Pass 1: L Sweep ---
            long long mul = 1; 
            auto q_it = group_start;
            int i = (*q_it)[0];
            while (i < n) {
                int next_event = i;
                while (next_event == i) {
                    mul = mul * (*q_it)[3] % MOD;
                    q_it++;
                    next_event = (q_it == group_end) ? n : (*q_it)[0];
                }
                if (mul != 1) {
                    for (; i < next_event; i += step) nums[i] = nums[i] * mul % MOD;
                } else {
                    i = next_event;
                }
            }

            // --- Pass 2: R Sweep ---
            sort(group_start, group_end, [](const auto& a, const auto& b) { return a[1] < b[1]; });
            
            i = offset;
            mul = 1;
            q_it = group_start;
            long long inv_mul = 1; 
            while (i < n) {
                int next_event =  (*q_it)[1];
                while (next_event < i) {
                    mul = mul * (*q_it)[3] % MOD;
                    q_it++;
                    next_event = (q_it == group_end) ? n-1 : (*q_it)[1];
                }
                inv_mul = get_inverse(mul);
                if (inv_mul != 1) {
                    for (; i <= next_event; i += step) {
                        nums[i] = nums[i] * inv_mul % MOD;
                    }
                } else {
                    i += ((next_event - i) / step + 1) * step;
                } 
           }
        }

        int xor_sum = 0;
        for (int val : nums) xor_sum ^= val;
        return xor_sum;
    }
};