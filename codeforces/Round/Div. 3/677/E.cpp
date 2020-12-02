#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    long long res = 2;
    for(int i=2;i<n;i++) res*=i;
    cout<<(res/n)<<endl;
    return 0;
}
