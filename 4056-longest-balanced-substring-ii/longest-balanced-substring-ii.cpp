
class Solution {
public:
    int calculatingForTwo(int f, int s, int skip, string st) {
        map<int, int> diff;
        int cf = 0, cs = 0;
        int maxC = 0;
        diff[0] = -1;
        for(int i=0;i<st.size();i++) {
            int val = st[i] - 'a';
            if(val == skip) {
                cf = 0;
                cs = 0;
                diff.clear();
                diff[0] = i;
                continue;
            }
            if(val==f) {
                cf++;
            } else {
                cs++;
            }
            int d = cf - cs;
            if(diff.find(d) != diff.end()) {
                maxC = max(maxC, (i-diff[d]));
            } else {
                diff[d] = i;
            }
        }
        return maxC;
    }
    int longestBalanced(string s) {
        int ans = 1;
        int con = 1;
        for(int i=1;i<s.size();i++) {
            if(s[i]==s[i-1]) {
                con++;
            } else {
                con = 1;
            }
            ans = max(con, ans);
        }
        ans = max(ans, calculatingForTwo(0,1,2,s));
        ans = max(ans, calculatingForTwo(1,2,0,s));
        ans = max(ans, calculatingForTwo(0,2,1,s));
        map< pair<int, int>, int > existing;
        int arr[4] = {0};
        existing[{0,0}] = -1;
        cout<<ans<<endl;
        for(int i=0;i<s.size();i++) {
            arr[s[i]-'a']++;
            int d1 = arr[0] - arr[1];
            int d2 = arr[0] - arr[2];
            if(existing.find({d1, d2}) != existing.end()) {
                ans = max(ans, i-existing[{d1,d2}]);
            } else {
                existing[{d1,d2}] = i;
            }
        }
        return ans;
    }
};

/*
    5 6 7

    1 1

    11 12 13
    100 0
*/