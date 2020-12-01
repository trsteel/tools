#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    long long n; cin>>n;
    vector<long long> a(n, 0);
    for(long i=1;i<n;i++) {
        cout<<"XOR "<<i<<" "<<(i+1)<<endl;
        cout.flush();
        cin>>a[i];
    }
    long long x, y, z, u, v, w;
    cout<<"AND 1 2"<<endl;
    cout.flush();
	cin>>x;
	cout<<"AND 1 3"<<endl;
    cout.flush();
	cin>>y;
	cout<<"AND 2 3"<<endl;
    cout.flush();
	cin>>z;
	u=2*x+a[1];
	v=2*y+(a[1]^a[2]);
	w=2*z+a[2];
	u=(u+v+w)/2-w;
	cout<<"! "<<u;
    for(long i=1;i<n;i++) {
        u^=a[i];
        cout<<" "<<u;
    }
    cout<<endl;
    return 0;
}