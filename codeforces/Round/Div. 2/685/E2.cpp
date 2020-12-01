#include <iostream>
#define N 100001
using namespace std;
 
int n, a[N], idx[N];
bool succ;
 
int main() {
	cin>>n; idx[0] = 1;
 
	for (int i=2; i<=n; i++) {
		cout<<"XOR 1 "<<i<<endl;
		cin>>a[i];
		if (idx[a[i]] && !succ) {
			cout<<"OR "<<idx[a[i]]<<' '<<i<<endl;
			cin>>a[1]; a[1] ^= a[i];
			succ = 1;
		}
		idx[a[i]] = i;
	}
	
	if (!succ) {
		int f, s;
		cout<<"AND 1 "<<idx[1]<<endl; cin>>f;
		cout<<"AND 1 "<<idx[2]<<endl; cin>>s;
		f |= s & 1; a[1] = f;
	}
 
	cout<<"! "<<a[1]<<' ';
	for (int j=2; j<=n; j++) cout<<(a[j]^a[1])<<' ';
	cout<<endl;
}