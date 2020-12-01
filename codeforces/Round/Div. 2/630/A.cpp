#include <iostream>

using namespace std;
long long t, a, b, c, d, x, y, x1, y1, x2, y2;

bool solve() {
    cin>>a>>b>>c>>d;
    cin>>x>>y>>x1>>y1>>x2>>y2;
    x+=b-a,y+=d-c;
    return x>=x1&&x<=x2&&y>=y1&&y<=y2&&(x2>x1||a+b==0)&&(y2-y1||c+d==0);
}

int main(){
    
    cin>>t;
    while(t--) {
        cout<<(solve()?"YES":"NO")<<endl;
    }
    return 0;
}