class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int i = nums.size() - 1;
        while(i>=0 && price >= nums[i]) {
        	i -= spans[i];
        }
        spans.push_back(nums.size()-i);
        nums.push_back(price);
        return spans.back();
    }
private:
	vector<int> nums;
	vector<int> spans;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */