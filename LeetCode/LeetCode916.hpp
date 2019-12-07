class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
		vector<int> counts(26, 0);
		for(auto& w: B) {
			vector<int> cnt(26, 0);
			for(auto& c: w) cnt[c-'a']++;
			for(int i=0;i<26;i++) {
				counts[i] = max(counts[i], cnt[i]);
			}
		} 
		vector<string> res;
		for(auto& w: A) {
			vector<int> cnt(26, 0);
			for(auto& c: w) cnt[c-'a']++;
			bool is_valid=true;
			for(int i=0;i<26;i++) {
				if(counts[i]>cnt[i]) {
					is_valid = false;
					break;
				}
			}
			if(is_valid) res.push_back(w);
		}
		return res;
    }
};