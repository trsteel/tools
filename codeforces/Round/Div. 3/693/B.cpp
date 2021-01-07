#include <iostream>

using namespace std;

int main(){
    long t, n, a;
    cin>>t;
    while(t--) {
        cin>>n;
        long one = 0, two = 0;
        for(int i=0;i<n;i++) {
            cin>>a;
            if(a==1) one++;
            else two++;
        }
        if(one%2==1) {
            cout<<"No"<<endl;
        } else if(two%2==1) {
            cout<<(one<2?"No":"Yes")<<endl;
        } else cout<<"Yes"<<endl;
    }
    return 0;
}