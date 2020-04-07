#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long T, n; cin>>T;
    for(long long t=1;t<=T;t++) {
        cin>>n;
        vector<vector<long long> > vec(n, vector<long long>(3));
        for(long long i=0;i<n;i++) {
            cin>>vec[i][1]>>vec[i][2];
            vec[i][0] = i;
        }
        sort(vec.begin(), vec.end(), [](vector<long long>& v1, vector<long long>& v2){
            return v1[1]==v2[1] ? v1[2]<v2[2] : v1[1] < v2[1];
        });
        string res(n, ' ');
        long long a = 0, b = 0;
        bool valid = true;
        for(auto& v: vec) {
            if(v[1]>=a) {a=v[2], res[v[0]]='C';}
            else if(v[1]>=b) {b=v[2], res[v[0]]='J';}
            else {valid = false; break; }
        }
        cout<<"Case #"<<t<<": "<<(valid?res:"IMPOSSIBLE")<<endl;
    }
    return 0;
}