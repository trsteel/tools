class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        map<int, vector<int>> g;
        vector<int> visited(numCourses, 0);
        for(auto& it: prerequisites) g[it.first].push_back(it.second);
        for(int i=0;i<numCourses;i++)
        	if (!dfs(g, visited, i)) return false;
        return true;
    }

    bool dfs(map<int, vector<int>>& g, vector<int>& visited, int n) {
    	if(visited[n]==-1) return false;
    	if(visited[n]==1) return true;
    	visited[n] = -1;
    	for(auto& i: g[n])
    		if(!dfs(g, visited, i)) return false;
    	visited[n] = 1;
    	return true;
    }
};