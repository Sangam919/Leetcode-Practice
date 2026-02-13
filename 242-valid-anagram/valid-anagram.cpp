class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> count;

        // Count characters in s
        for (char c : s) count[c]++;

        // Subtract counts using t
        for (char c : t) {
            if (--count[c] < 0) return false;
        }

        return true;
    }
};


// class Solution {            
// public:
//     bool isAnagram(string s, string t) {
//         if(s.length() != t.length()){
//             return false;
//         }
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
//         if(s == t){
//             return true;  
//         }
//         return false;
//     }
// }; 