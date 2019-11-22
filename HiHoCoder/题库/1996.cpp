#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> num(n);
    for(int i=0;i<n;i++) cin>>num[i];
    int q, l, r;
    cin>>q;
    while(q--) {
        cin>>l>>r;
        int ans = 0, one = 0;
        for(int i=l-1;i<r;i++) {
            if(num[i]==1) {one++; continue;}
            if(one>0) ans++, one--;
        }
        cout<<ans<<endl;
    }
    return 0;
}