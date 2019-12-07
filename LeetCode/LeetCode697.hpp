class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> index, start;
        int ans = 0, digree=0;
        int max_cnt=0;
        for(int i=0;i<nums.size();i++) {
        	if(start.find(nums[i]) == start.end()){
        		start[nums[i]] = i;
        	}
        	index[nums[i]]++;
        	if(index[nums[i]] > digree) {
        		digree = index[nums[i]];
        		ans = i - start[nums[i]]+1;
        	} else if(index[nums[i]] == digree) {
        		ans = min(ans, i - start[nums[i]]+1);
        	}
        }
        return ans;
    }
};