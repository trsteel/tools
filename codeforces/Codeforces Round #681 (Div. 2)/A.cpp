#include <iostream>
#include <set>
using namespace std;


int main(){
    long t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=2*n+2;i<=4*n;i+=2) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
