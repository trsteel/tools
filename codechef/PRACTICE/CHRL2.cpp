#include <iostream>
#include <vector>

using namespace std;

int main(){
    string s; cin>>s;
    vector<int> cnt(4, 0);
    for(char c: s) {
        switch(c) {
        case 'C': cnt[0]++; break;
        case 'H': cnt[1] = min(cnt[0], cnt[1]+1); break;
        case 'E': cnt[2] = min(cnt[1], cnt[2]+1); break;
        case 'F': cnt[3] = min(cnt[2], cnt[3]+1); break;
        }
    }
    cout<<cnt[3]<<endl;
    return 0;
}