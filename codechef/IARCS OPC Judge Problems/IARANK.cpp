#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> vec;
    int num;
    while(n--) {
        cin>>num;
        auto it = upper_bound(vec.begin(), vec.end(), num);
        cout<<(vec.end()-it+1)<<endl;
        vec.insert(it, num);
    }
    return 0;
}