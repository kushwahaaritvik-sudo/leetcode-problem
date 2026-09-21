class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> answer(k, 0);

       
        vector<long long> prev(k, 0);

        for (int num : nums) {
            vector<long long> curr(k, 0);

            int value = num % k;

            curr[value]++;

            for (int remainder = 0; remainder < k; remainder++) {
                int newRemainder =
                    (1LL * remainder * value) % k;

                curr[newRemainder] += prev[remainder];
            }

            for (int remainder = 0; remainder < k; remainder++) {
                answer[remainder] += curr[remainder];
            }

            prev = curr;
        }

        return answer;
    }
};