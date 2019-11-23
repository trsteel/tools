#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int m; cin>>m;
    vector<int> len(m);
    for(int i=0;i<m;i++) cin>>len[i];
    unordered_map<string, vector<int> > topics;
    string s;
    for(int i=0;i<m;i++) {
        for(int j=0;j<len[i];j++) {
            cin>>s; topics[s].push_back(i);
        }
    }
    vector<int> res(m, 0);
    while(cin>>s) {
        if(topics.find(s)!=topics.end()) {
            for(int i: topics[s]) res[i]++;
        }
        if(cin.get()=='\n') break;
    }
    for(int i: res) cout<<i<<endl;
    return 0;
}