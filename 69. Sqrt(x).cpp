// class Solution {
// public:
//     int mySqrt(int x) {
//         if (x == 0) return 0;
//         long guess = x;
//         while (guess * guess > x) {
//             guess = (guess + x / guess) / 2;
//         }

//         return guess;
//     }
// };



class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        int low = 1, high = x, ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (mid * mid == x) {
                return mid;
            } else if (mid * mid < x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
