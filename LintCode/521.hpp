class Solution {
public:
    /**
     * @param nums: an array of integers
     * @return: the number of unique integers
     */
    int deduplication(vector<int> &nums) {
        // write your code here
        if(nums.size()<2) return nums.size();
        int start=0, end = nums.size()-1;
        while(start<end) {
            while(start<end && nums[start]==nums[end]) end--;
            for(int i=start+1;i<=end;i++) {
                if(nums[i]==nums[start]){
                    swap(nums, i, end--);
                    while(start<end && nums[start]==nums[end]) end--;
                }
            }
            start++;
        }
        return end+1;
    }
    void swap(vector<int>& nums, int i, int j) {
        if(i==j) return;
        int t = nums[i];
        nums[i]=nums[j];
        nums[j] = t;
    }
};