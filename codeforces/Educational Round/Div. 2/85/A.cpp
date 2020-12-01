#include <iostream>

using namespace std;

int main(){
    long t, n, p, c, a, b; cin>>t;
    while(t--) {
        cin>>n;
        bool valid = true;
        a = 0, b = 0;
        while(n--) {
            cin>>p>>c;
            if(p<c||p<a||c<b||c+a>p+b) valid = false;
            a = p, b = c;
        }
        cout<<(valid?"YES":"NO")<<endl;
    }
    return 0;
}