/**
 * 关键点: 去重+贪心 km算法不能全过
 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

long beautiful(string& a, string& b) {
    long m = a.size(), n = b.size();
    long k = min(m, n);
    for(long i=0;i<k; i++) {
        if(a[i]!=b[i] || a[m-i-1]!=b[n-i-1]) return i*i;
    }
    return k*k;
}

long cal(vector<string>& vec) {
    unordered_map<string, int> um;
    for(string& s: vec) um[s]++;
    long res = 0;
    vec.clear();
    for(auto& it: um) {
        res += it.first.size() * it.first.size() * (it.second/2);
        if(it.second%2==1) vec.push_back(it.first);
    }
    if(vec.empty()) return res;
    int n = vec.size();
    vector<vector<long> > tmp;
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) {
        long ans = beautiful(vec[i], vec[j]);
        if(ans>0) tmp.push_back({i, j, ans});
    }
    sort(tmp.begin(), tmp.end(), [](vector<long>& v1, vector<long>& v2) {
        return v1[2] > v2[2];
    });
    vector<bool> vis(n);
    for(auto& v: tmp) {
        if(vis[v[0]] || vis[v[1]]) continue;
        res += v[2], vis[v[0]]=vis[v[1]]=true;
    }
    return res;
}

int main() {
	// your code goes here
	int t, n; cin>>t;
	while(t--) {
	    cin>>n;
	    vector<string> vec(n);
	    for(int i=0;i<n;i++) cin>>vec[i];
	    cout<<cal(vec)<<endl;
	}
	return 0;
}