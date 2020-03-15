#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    long long t, n, num; cin>>t;
    unordered_set<long long> us;
    while(t--) {
        cin>>n;
        us.clear();
        while(n--) {
            cin>>num; us.insert(num);
        }
        cout<<us.size()<<endl;
    }
    return 0;
}