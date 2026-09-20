class Solution {
public:
    int reverseDegree(string s) {
        long long ans = 0;  
        for (int i = 0; i < (int)s.size(); ++i) {
            int revValue = 'z' - s[i] + 1;
            int pos = i + 1;
            ans += 1LL * revValue * pos;
        }
        return (int)ans;  
    }
};