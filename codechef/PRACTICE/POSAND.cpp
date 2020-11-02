#include <iostream>
using namespace std;


int main() {
    int t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        if(n==1) {
            cout<<1<<endl; continue;
        }
        if(n==3) {
            cout<<2<<" "<<3<<" "<<1<<endl;
            continue;
        }
        if((n&(n-1))==0) {
            cout<<-1<<endl; continue;
        }
        int count = n-3, i=5;
        cout<<2<<" "<<3<<" "<<1;
        while(count > 0) {
            if(count==1) {
                cout<<" "<<((i%2==1)?i-1:i);
                count--;
                continue;
            }
            if(i%2) {
                cout<<" "<<i<<" "<<i-1;
                i+=1;
            } else {
                cout<<" "<<i<<" "<<i+1;
                i+=3;
            }
            count-=2;
        }
        cout<<endl;
    }
}