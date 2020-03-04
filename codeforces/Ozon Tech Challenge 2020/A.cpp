#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t, n; cin>>t;
    while(t--) {
        cin>>n;
        vector<int> x(n), y(n);
        for(int i=0;i<n;i++) cin>>x[i];
        for(int i=0;i<n;i++) cin>>y[i];
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        for(int i: x) cout<<i<<" ";
        cout<<endl;
        for(int i: y) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}