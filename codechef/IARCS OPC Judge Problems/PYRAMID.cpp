#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int cal(map<int, int>& m) {
    int last = 0;
    for(auto& it: m) {
        last = min(it.first, last+it.second);
    }
    return last;
}

int main(){
    int n; cin>>n;
    map<int, int> m;
    int i, j;
    while(n--) {
        cin>>i>>j;
        m[min(i, j)]++;
    }
    cout<<cal(m)<<endl;
    return 0;
}