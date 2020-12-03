#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    long long cnt = 0, s = 0, n, x;
    cin>>n;
    unordered_set<long long> us;
    us.insert(0);
    while(n--) {
        cin>>x; s += x;
        if(us.count(s)) {
            cnt++; s = x;
            us.clear();
            us.insert(0);
            us.insert(s);
        } else us.insert(s);
    }
    cout<<cnt<<endl;
    return 0;
}
