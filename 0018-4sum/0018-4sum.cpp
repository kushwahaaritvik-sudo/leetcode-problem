#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 4) return result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                long long twoSum = (long long)nums[i] + nums[j];
                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long total = twoSum + nums[left] + nums[right];

                    if (total == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        int leftVal = nums[left];
                        int rightVal = nums[right];
                        while (left < right && nums[left] == leftVal) ++left;
                        while (left < right && nums[right] == rightVal) --right;
                    } else if (total < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }

        return result;
    }
};