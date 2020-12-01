#include <iostream>
using namespace std;

int main() {
    int n, p; cin>>n;
    while(n--) {
        cin>>p;
        for(int i=2;i<=p;i++) cout<<i<<" ";
        cout<<1<<endl;
    }
    return 0;
}