#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cal(vector<vector<int> >& vec) {
    sort(vec.begin(), vec.end(), [](vector<int>& v1, vector<int>& v2){
        return v1[1]==v2[1] ? v1[0] < v2[0] : v1[1] < v2[1];
    });
    int res = 0, ans = -1;
    for(auto& v: vec) {
        if(v[0]<=ans) continue;
        res++, ans = v[1];
    }
    return res;
}

int main(){
    int n; cin>>n;
    vector<vector<int> > vec(n);
    int s, d;
    for(int i=0;i<n;i++) {
        cin>>s>>d;
        vec[i] = {s, s+d};
    }
    cout<<cal(vec)<<endl;
    return 0;
}