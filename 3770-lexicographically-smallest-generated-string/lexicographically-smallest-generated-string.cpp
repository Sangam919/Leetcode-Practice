class Solution {
private:
    vector<int> computeZ(const string &s) {
        int n = s.size();
        vector<int> z(n, 0);
        int left = 0, right = 0;

        for (int i = 1; i < n; i++) {
            if (i <= right)
                z[i] = min(z[i - left], right - i + 1);

            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                left = i;
                right = i + z[i];
                z[i]++;
            }
        }

        z[0] = n;
        return z;
    }

public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        string word(n + m - 1, '*');
        vector<int> z = computeZ(str2);
        int lastMatchStart = -m;

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') continue;

            int overlap = max(0, lastMatchStart + m - i);

            if (overlap && z[m - overlap] < overlap)
                return "";

            for (int j = overlap; j < m; j++) {
                word[i + j] = str2[j];
            }

            lastMatchStart = i;
        }

        vector<int> lastWildcard(word.size());
        int last = -1;

        for (int i = 0; i < word.size(); i++) {
            if (word[i] == '*') {
                word[i] = 'a';
                last = i;
            }
            lastWildcard[i] = last;
        }

        z = computeZ(str2 + word);

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T' || z[m + i] < m)
                continue;

            int pos = lastWildcard[i + m - 1];

            if (pos < i)
                return "";

            word[pos] = 'b'; 
            i = pos;         
        }

        return word;
    }
};