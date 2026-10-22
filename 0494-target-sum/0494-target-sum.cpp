
class Solution {
private:
    map<pair<int, int>, int> dp;

    int fun(int i, int s, int target, vector<int>& nums) {
        if (i == nums.size()) {
            return (s == target) ? 1 : 0;
        }

        // Check if state (i, s) is already memoized
        if (dp.count({i, s})) {
            return dp[{i, s}];
        }

        // Branch 1: add nums[i]
        int l = fun(i + 1, s + nums[i], target, nums);
        // Branch 2: subtract nums[i]
        int r = fun(i + 1, s - nums[i], target, nums);

        return dp[{i, s}] = l + r;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        dp.clear();
        return fun(0, 0, target, nums);
    }
};
