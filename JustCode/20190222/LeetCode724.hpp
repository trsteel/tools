class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size()==0) {
        	return -1;
        } else if(nums.size()==1) {
        	return 0;
        }
        vector<long> sum(nums.size()+2, 0);
        for(int i=0;i<nums.size();i++) {
        	sum[i+1] = sum[i]+nums[i];
        }
        for(int i=0;i<nums.size();i++) {
        	// cout<<sum[i]<<" "<<sum[i+1]<<" "<<sum[nums.size()]<<endl;
        	if((sum[i]+sum[i+1]) == sum[nums.size()]) {
        		return i;
        	}
        }
        return -1; 
    }
};