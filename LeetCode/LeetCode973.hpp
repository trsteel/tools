class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        map<int, int, less<int>> m;
        for(int i=0;i<points.size();i++) {
        	int d = points[i][0]*points[i][0] + points[i][1]*points[i][1];
        	m[d] = i;
        }
        vector<vector<int>> res;
        for(auto& it: m) {
        	res.push_back(points[it.second]);
        	if(res.size()==K) break;
        }
        return res;
    }
};