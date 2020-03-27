#include <iostream>

using namespace std;

int main(){
    long long t, h, x; cin>>t;
    while(t--) {
        cin>>h;
        x=1;
        do {
            cout<<"2 "<<x<<" "<<h<<endl;
            cin>>x; cout<<"1 "<<x<<endl;
            cin>>h;
        } while(h>2);
        cout<<"2 "<<x<<" "<<h<<endl;
        cin>>x; cout<<"3 "<<x<<endl;
        cin>>x;
    }
    return 0;
}