#include <iostream>
using namespace std;
int main()
{
	int n,m,k;cin>>n>>m>>k;
	string ans;
	ans+=string(n-1,'D')+string(m-1,'R');
	for(int i=0;i<m;i++){
		ans+=string(n-1,"UD"[i&1]);
		if(i!=m-1) ans+='L';
	}
	cout<<ans.size()<<endl<<ans;
	return 0;
}