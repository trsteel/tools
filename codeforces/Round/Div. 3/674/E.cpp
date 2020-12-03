#include <iostream>

using namespace std;

int main() {
    int n, a, b, c, d, e, f;
    cin>>n>>a>>b>>c>>d>>e>>f;
    cout<<n-min(a, n-e)-min(b, n-f)-min(c, n-d)<<" "<<min(a, e)+min(b, f)+min(c, d)<<endl;
    return 0;
}
