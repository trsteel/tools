#include <iostream>

using namespace std;

int main(){
    long long t, p, f, cs, cw, s, w;
    cin>>t;
    while(t--) {
        cin>>p>>f>>cs>>cw>>s>>w;
        if(s > w) swap(s, w), swap(cs, cw);
        int m=0;
		for(int i=0;i<=cs;i++){
			if(i*s>p) break;
			int j=min(cw,(p-i*s)/w);
			int x=min(cs-i,f/s);
			int y=min(cw-j,(f-x*s)/w);
			m=max(m,i+j+x+y);
		}
		cout<<m<<endl;
    }
    return 0;
}