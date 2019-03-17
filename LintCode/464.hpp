// TLE
class Solution {
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
    void sortIntegers2(vector<int> &A) {
        // write your code here
        qsort(A, 0, A.size()-1);
    }
    void qsort(vector<int>& nums, int l, int r) {
        if(l>=r-1) return;
        int i=l, j=r;
        while(i<j) {
            while(i<j && nums[i]<=nums[j]) j--;
            if(i==j) break;
            swap(nums, i, j);
            while(i<j && nums[i]<=nums[j]) i++;
            if(i==j) break;
            swap(nums, i, j);
        }
        qsort(nums, l, i-1);
        qsort(nums, i+1, r);
    }
    void swap(vector<int>& nums, int i, int j) {
        if(i==j) return;
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
};