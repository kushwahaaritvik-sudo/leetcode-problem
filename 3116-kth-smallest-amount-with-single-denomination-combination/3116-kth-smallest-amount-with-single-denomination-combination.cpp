#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        int totalMasks = 1 << n;

        long long minCoin = *min_element(coins.begin(), coins.end());
        long long high = minCoin * 1LL * k;

        // lcmValue[mask] = LCM of all coins in mask.
        // Values greater than high are clipped to high + 1,
        // because they cannot contribute for any binary-search value.
        vector<long long> lcmValue(totalMasks, 1);
        vector<int> subsetSize(totalMasks, 0);

        for (int mask = 1; mask < totalMasks; mask++) {
            int bit = __builtin_ctz(mask);
            int previous = mask & (mask - 1);

            subsetSize[mask] = subsetSize[previous] + 1;

            long long coin = coins[bit];
            long long g = gcd(lcmValue[previous], coin);

            __int128 candidate =
                (__int128)(lcmValue[previous] / g) * coin;

            if (candidate > high) {
                lcmValue[mask] = high + 1;
            } else {
                lcmValue[mask] = (long long)candidate;
            }
        }

        auto countAmounts = [&](long long x) -> long long {
            long long result = 0;

            for (int mask = 1; mask < totalMasks; mask++) {
                long long currentLcm = lcmValue[mask];

                if (currentLcm > x) {
                    continue;
                }

                long long contribution = x / currentLcm;

                if (subsetSize[mask] % 2 == 1) {
                    result += contribution;
                } else {
                    result -= contribution;
                }
            }

            return result;
        };

        long long low = 1;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (countAmounts(mid) >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};