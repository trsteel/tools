/*
 * dp算法要考慮越界的情況，某些中间项是冗余的。
 */
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int x : nums) {
                if (i >= x) {
                    dp[i] += dp[i - x];
                    dp[i] %= 1L<<32 - 1;
                }
            }
        }
        return dp[target];
    }
};