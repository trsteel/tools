#include <iostream>

using namespace std;

int main(){
    long t, n, a, pre;
    cin>>t;
    while(t--){
        cin>>n>>pre;
        bool equal = true;
        for(int i=1;i<n;i++) {
            cin>>a; 
            if(a!=pre) equal = false;
        }
        cout<<(equal ? n : 1)<<endl;
    }
    return 0;
}