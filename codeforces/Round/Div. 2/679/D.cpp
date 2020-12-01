#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long n;
    cin>>n;
    vector<pair<char, int>> op(2*n);
    for(auto& v: op) {
        cin>>v.first;
        if(v.first=='-') cin>>v.second;
    }
    reverse(op.begin(), op.end());
    set<int> st;
    vector<int> res;
    for(auto& v: op) {
        if(v.first=='+') {
            if(st.empty()) {
                cout<<"NO"<<endl; return 0;
            }
            res.push_back(*st.begin());
            st.erase(st.begin());
        } else {
            st.insert(v.second);
        }
    }
    for(int i: st) res.push_back(i);
    reverse(res.begin(), res.end());
    st.clear();
    reverse(op.begin(), op.end());
    int idx = 0;
    for(auto& v: op) {
        if(v.first=='+') {
            st.insert(res[idx++]);
        } else {
            if(*st.begin() != v.second) {
                cout<<"NO"<<endl; return 0;
            } else st.erase(st.begin());
        }
    }
    cout<<"YES"<<endl;
    for(int i: res) cout<<i<<" ";
    cout<<endl;
    return 0;
}
