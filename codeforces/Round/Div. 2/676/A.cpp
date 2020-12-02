#include <iostream>

using namespace std;

int main() {
    long t, a, b;
    cin>>t;
    while(t--) {
        cin>>a>>b;
        cout<<(a^b)<<endl;
    }
    return 0;
}
