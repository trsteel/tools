#include <iostream>
#include <set>
using namespace std;

int main(){
    int n, m; cin>>n>>m;
    int t = n+m, i;
    set<int> st;
    while(t--) {
        cin>>i;
        if(i!=-1) {st.insert(i); continue;}
        if(st.empty()) cout<<0<<endl;
        else {
            auto it = --st.end();
            cout<<(*it)<<endl;
            st.erase(it);
        }
    }
    return 0;
}