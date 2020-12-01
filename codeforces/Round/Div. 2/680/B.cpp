#include <iostream>
using namespace std;

int main() {
    long t, a, b, c, d;
    cin>>t;
    while(t--) {
        cin>>a>>b>>c>>d;
        cout<<max(a+b, c+d)<<endl;
    }
    return 0;
}