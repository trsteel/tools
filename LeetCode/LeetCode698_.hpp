class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto n: nums) sum+=n;
        int devide = sum / k;
        if(devide*k!=sum) return false;
        sort(nums.begin(), nums.end(), [](int a, int b){return a>b;});
        vector<int> visited(nums.size(), 0);
        return canPartitionKSubsets(nums, visited, k, devide, 0, 0, 0);
    }

    bool canPartitionKSubsets(vector<int>& nums, vector<int>& visited, int k, int target, int start, int index, int sum) {
        if(k==1) return true;
        if(sum==target && index>0) return canPartitionKSubsets(nums, visited, k-1, target, 0, 0, 0);
        for(int i=start;i<nums.size();i++) {
            if(visited[i]) continue;
            visited[i] = 1;
            if(canPartitionKSubsets(nums, visited, k, target, i+1, index++, sum+nums[i])) return true;
            visited[i] = 0;
        }
        return false;
    }
};