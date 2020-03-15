/**
 * 关键点: 边界条件判断异常艰难，处理逻辑收敛在find函数里
 **/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find(vector<int>& vec, int l, int r) {
    auto itl = lower_bound(vec.begin(), vec.end(), l);
    if(itl == vec.end()) return 0;
    int idxl = itl - vec.begin();
    if(idxl%2==1) idxl += vec[idxl]-l < 1 ? 1 : -1;
    int idxr = upper_bound(vec.begin(), vec.end(), r) - vec.begin();
    if(idxr%2==1) idxr += r-vec[idxr-1] >= 1 ? 1 : -1;
    return (idxr-idxl)/2;
}

int main(){
    int n, q; cin>>n>>q;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    vector<int> inc, dec;
    int incl=0, decl=0;
    for(int i=1;i<n;i++) {
        if(vec[i]<=vec[i-1]) {
            if(i-incl>1) { inc.push_back(incl); inc.push_back(i-1); }
            incl = i;
        }
        if(vec[i]>=vec[i-1]) {
            if(i-decl>1) { dec.push_back(decl); dec.push_back(i-1); }
            decl = i;
        }
    }
    if(n-incl>1) { inc.push_back(incl); inc.push_back(n-1); }
    if(n-decl>1) { dec.push_back(decl); dec.push_back(n-1); }
    int l, r;
    while(q--) {
        cin>>l>>r;
        int a = find(inc, l-1, r-1);
        int b = find(dec, l-1, r-1);
        cout<<(a==b?"YES":"NO")<<endl;
    }
    return 0;
}