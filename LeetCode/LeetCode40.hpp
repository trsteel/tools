class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cache;
        backstrap(candidates, 0, target, cache, res);
        return res;
    }
    void backstrap(vector<int>& nums, int start, int target, vector<int>& cache, vector<vector<int>>& res) {
    	if(target==0) {
    		res.push_back(cache);
    		return;
    	}
    	for(int i=start;i<nums.size();i++) {
    		if(nums[i] > target) continue;
    		if(i>start && nums[i]==nums[i-1]) continue;
    		cache.push_back(nums[i]);
    		backstrap(nums, i+1, target-nums[i], cache, res);
    		cache.pop_back();
    	}
    }
};