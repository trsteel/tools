class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        map<int, int> ans;
        sort(people.begin(), people.end(), [](int a, int b) { return a>b;});
        int res = 0;
        for(auto p: people) {
            bool is_added = false;
            for(auto& a: ans) {
                if(a.first+p<=limit){
                    res++;
                    if(--a.second==0) 
                        ans.erase(a.first);
                    is_added = true;
                    break;
                }
            }
            if(!is_added) ans[p]++;
        }
        for(auto& it: ans) res += it.second;
        return res;
    }
};