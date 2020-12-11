#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long t, n;
    string a;
    cin>>t;
    while(t--) {
        cin>>n>>a;
        sort(a.begin(), a.end());
        cout<<a<<endl;
    }
    return 0;
}