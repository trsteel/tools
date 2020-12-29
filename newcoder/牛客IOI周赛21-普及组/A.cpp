#include <iostream>

using namespace std;

int find(int y, int m) {
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12) return 31;
    if(m==2) {
        if(y%400==0) return 29;
        if(y%4==0 && y%100>0) return 29;
        return 28;
    }
    return 30;
}

int main(){
    long a, b, h[7], c, x, cnt[7];
    cin>>a>>b;
    for(int i=0;i<7;i++) {
        cin>>h[i]; cnt[i] = 0;
    }
    c = find(a, b);
    for(int i=0;i<c;i++) {
        cin>>x; cnt[i%7]+=x;
    }
    long res = -1;
    for(int i=0;i<7;i++) {
        long ans = 0;
        for(int j=0;j<7;j++) {
            ans += h[(i+j)%7]*cnt[j];
        }
        if(res==-1 || ans < res) res = ans;
    }
    cout<<res<<endl;
    return 0;
}