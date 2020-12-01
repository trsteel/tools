#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    long t, n, b;
    cin>>t;
    while(t--) {
        cin>>n;
        unordered_set<long> vis;
        bool find = false;
        for(int i=0;i<n;i++) {
            cin>>b;
            if(!find && vis.count(b)) {
                find = true; continue;
            }
            vis.insert(b);
        }
        cout<<(find?"YES":"NO")<<endl;
    }
    return 0;
}