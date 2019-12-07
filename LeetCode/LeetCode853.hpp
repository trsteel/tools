class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
    	map<int, double, greater<int>> time;
    	for(int i=0;i<position.size();i++) {
    		time[position[i]] = ((double)target-position[i])/speed[i];
    	}
    	int ans = 0;
    	double last_time = 0;
    	for(auto& t: time) {
    		if(t.second > last_time) {
    			ans ++;
    			last_time = t.second;
    		}
    	}
    	return ans;
    }
};