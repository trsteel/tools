class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> ans(N+1, 0);
        for(auto& t: trust) {
        	ans[t[0]] = -1;
        	if(ans[t[1]]!=-1) ans[t[1]]++;
        }
        for(int i=1;i<=N;i++) {
        	if(ans[i]==N-1) return i;
        }
        return -1;
    }
};