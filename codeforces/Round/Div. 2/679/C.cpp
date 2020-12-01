#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    long a[6], n, b[100001], in[100001];
    for (long &i : a) cin >> i;
    sort(a, a+6);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> b[i];
    sort(b, b+n);
    set<pair<long, long>> st;
    for(int i=0;i<n;i++) {
        in[i] = 5;
        st.insert({b[i]-a[5], i});
    }
    long res = (--st.end())->first - st.begin()->first;
    while(true) {
        auto p = *st.begin();
        st.erase(st.begin());
        if(in[p.second]--==0) break;
        st.insert({b[p.second]-a[in[p.second]], p.second});
        res = min(res, (--st.end())->first - st.begin()->first);
    }
    cout<<res<<endl;
    return 0;
}
