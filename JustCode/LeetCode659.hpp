class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, int> counts;
        vector<int> distincts;
        for(int num: nums) {
            if(++counts[num]==1) distincts.push_back(num);
        }
        // for(auto d: distincts) cout<<d<<" ";
        // cout<<endl;
        if(distincts.size()<3) return false;
        int i = 0;
        while(i<distincts.size()-2) {
            int start = distincts[i];
            if(counts[start]--==0) return false;
            if(counts[start+1]--==0) return false;
            if(counts[start+2]--==0) return false;
            while(i<distincts.size() && counts[distincts[i]]==0) counts.erase(distincts[i++]);
            int j=start+3;
            while(j<=distincts.back() && counts[j]>counts[j-1]) {
                if(--counts[j++]==0) counts.erase(distincts[i++]);
            }
            // for(auto d: counts) cout<<d.first<<" "<<d.second<<" ";
            // cout<<endl;
        }
        return i==distincts.size();
    }
};