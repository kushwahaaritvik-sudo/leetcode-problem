class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256, -1);

        int left = 0;
        int answer = 0;

        for (int right = 0; right < s.size(); right++) {
            unsigned char current = s[right];

            left = max(left, lastIndex[current] + 1);

            lastIndex[current] = right;

            answer = max(answer, right - left + 1);
        }

        return answer;
    }
};