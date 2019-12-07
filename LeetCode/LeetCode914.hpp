class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int> counts;
        for(auto& d : deck) counts[d]++;
        for(int i=2;;i++) {
            bool succ = true;
            for(auto& it: counts) {
                if(it.second<i) return false;
                if(it.second%i) {
                    succ = false;
                    break;
                }
            }
            if(succ) return true;
        }
        return true;
    }
};