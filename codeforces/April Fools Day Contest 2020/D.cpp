#include <iostream>

using namespace std;

int main(){
    string s; cin>>s;
    cout<<((s.back()-'0')%2)<<endl;
    return 0;
}