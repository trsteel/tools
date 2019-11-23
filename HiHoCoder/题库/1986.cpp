#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n; cin>>n;
    unordered_map<int, int> cnt;
    int i, max_freq;
    while(n--) {cin>>i; max_freq = max(max_freq, ++cnt[i]);}
    // cout<<cnt.size()<<max_freq<<endl;
    vector<vector<int> > freq(max_freq+1);
    for(unordered_map<int, int>::iterator it=cnt.begin(); it!=cnt.end();it++){
        freq[it->second].push_back(it->first);
    };
    int res = 0;
    for(int i=max_freq; i>0;i--) {
        if(freq[i].size()<2) continue;
        freq[i-1].insert(freq[i-1].end(), freq[i].begin()+1, freq[i].end());
        res += freq[i].size()-1;
    }
    cout<<res<<endl;
    return 0;
}