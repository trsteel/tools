#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; cin>>n;
    string s; cin>>s;
    vector<int> vec(26, 0);
    for(char c: s) vec[c-'a']++, n-=c-'a'+1;
    if(n==0) {cout<<0<<endl; return 0; }
    int res = 0;
    if(n>0) {
        for(int i=25;i>=0;i--) {
            while(vec[i]>0) {
                vec[i]--, n -= i, res++;
                if(n<=0) {cout<<res<<endl; return 0;}
            }
        }
    } else {
        for(int i=0; i<26; i++) {
            while(vec[i]>0) {
                n += 25-i, vec[i]--, res++;
                if(n>=0) {cout<<res<<endl; return 0;}
            }
        }
    }
    cout<<res<<endl;
    return 0;
}