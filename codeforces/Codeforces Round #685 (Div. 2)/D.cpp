#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    long long t, d, k;
    cin>>t;
    while(t--) {
        cin>>d>>k;
        d *= d;
        long l = sqrt(d/2)/k;
        bool win = (l*k)*(l*k)+((l+1)*k)*((l+1)*k)<=d;
        cout<<(win?"Ashish":"Utkarsh")<<endl;
    }
    return 0;
}