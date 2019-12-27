#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cp(int x, int y) {
    string s1 = to_string(x), s2 = to_string(y);
    int m = s1.size(), n = s2.size(), i=0;
    while(i<m && i<n) {
        if(s1[i]!=s2[i]) return s1[i] < s2[i] ? -1 : 1;
        i++;
    }
    if(m==n) return 0;
    return m < n ? -1 : 1;
}

bool cp(vector<int>& v1, vector<int>& v2) {
    int m = v1.size(), n = v2.size(), i=0, ans;
    while(i<m && i<n) {
        ans = cp(v1[i], v2[i]);
        if(ans != 0) return ans == -1;
        i++;
    }
    return m < n;
}

vector<int> cal(vector<vector<int> >& vec) {
    int n = vec.size();
    vector<int> idx(n);
    for(int i=0;i<n;i++) idx[i] = i;
    sort(idx.begin(), idx.end(), [&vec](int i, int j){
        return cp(vec[i], vec[j]);
    });
    return idx;
}

int main(){
    int n; cin>>n;
    vector<vector<int> > vec(n);
    int i=0;
    int num;
    while(i<n) {
        cin>>num;
        if(num==-1) i++;
        else vec[i].push_back(num);
    }
    auto idx = cal(vec);
    for(int ii: idx) {
        for(int i: vec[ii]) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}