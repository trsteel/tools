#include <iostream>
#include <set>
#include <vector>
using namespace std;
const long long maxn = 50001, maxx = 1e9 + 1;
long long n, x;
set<long long> st;

long long find_l(long long p, long long d) {
    // cout<<"L"<<" "<<p<<" "<<d<<" ";
    long long pos = *st.begin();
    while(d <= p && pos <= *(--st.end())) {
        auto it = st.upper_bound(pos+d);
        if(it == st.begin()) break;
        if(it == st.end()) {
            pos = *(--st.end()); break;
        }
        if(*(--it)==pos) {
            d = (*(++it)) - pos;
        } else {
            pos = *it, d+=2;
        }
    }
    // cout<<pos<<endl;
    return pos;
}

long long find_r(long long p, long long d) {
    // cout<<"R"<<" "<<p<<" "<<d<<" ";
    long long pos = *(--st.end());
    while(d <= p && pos >= *st.begin()) {
        auto it = st.lower_bound(pos-d);
        if(it == st.end()) break;
        if(it == st.begin()) {
            pos = *st.begin(); break;
        }
        if(*it < pos) {
            pos = *it, d+=2;
        } else {
            d = pos - (*(--it));
        }
    }
    // cout<<pos<<endl;
    return pos;
}

bool valid(long long p) {
    if(find_l(p, 1) >= find_r(p, 1)) return true;
    if(find_l(p, 2) >= find_r(p, 2)) return true;
    if(find_r(p-2, 1) - find_l(p-2, 1) <= 2*p) return true;
    if(find_r(p-2, 2) - find_l(p-2, 2) <= 2*p) return true;
    return false;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>x; st.insert(x*2);
    }
    long long le = 2, ri = maxx*2, res = maxx*2;
    while(le <= ri) {
        long long mid = (le+ri)>>1;
        if(valid(mid)) {
            res = min(res, mid); ri = mid - 1;
        } else le = mid + 1;
    }
    cout<<(res/2)<<"."<<(res%2==1?5:0)<<endl;
    return 0;
}