#include <iostream>

using namespace std;

int main(){
    int n; cin>>n;
    int diff = 0, a, b, x=0, y=0, d;
    for(int i=1;i<=n;i++) {
        cin>>a>>b;
        x += a, y += b;
        d = x-y;
        if(abs(d)>abs(diff)) {diff = d; }
    }
    cout<<(diff>0?1:2)<<" "<<abs(diff)<<endl;
    return 0;
}