#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        vector<int> p(n);
        for(int &i: p) cin>>i;
        reverse(p.begin(),p.end());
        for(int i:p) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}