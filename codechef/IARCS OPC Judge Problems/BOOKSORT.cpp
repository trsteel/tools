#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> vec;
    int num;
    for(int i=0;i<n;i++) {
        cin>>num;
        auto it = lower_bound(vec.begin(), vec.end(), num);
        if(it == vec.end()) vec.push_back(num);
        else *it = num;
    }
    cout<<(n-vec.size())<<endl;
    return 0;
}