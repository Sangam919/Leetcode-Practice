class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        // Group anagrams
        for (const string& s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(s);
        }

        // Prepare the result
        vector<vector<string>> result;
        for (const auto& pair : mp) {
            result.push_back(pair.second);
        }

        return result;
    }
};