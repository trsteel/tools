#include <iostream>

using namespace std;

int main() {
    long long t, a, b, c;
    cin>>t;
    while(t--) {
        cin>>a>>b>>c;
        cout<<(a+b+c-1)<<endl;
    }
    return 0;
}
