class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        double max_sum = 0;
        for(int i=0;i<nums.size();i++) {
        	if(i<k) {
        		sum += nums[i];
        		max_sum = sum;
        	} else {
        		sum += nums[i] - nums[i-k];
        		if(max_sum < sum) max_sum = sum;
        	}
        }
        return max_sum/k;
    }
};