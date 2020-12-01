#include <iostream>

using namespace std;

int main(){
    int t;
	cin >> t;
	while(t--){
		int n ,m ,a = 1;
		cin >> n >> m;
		for(int i=0; (1<<i)<=n; i++)
			a = 1LL*a*min(n-(1<<i)+2 ,(1<<i)+1)%m;
		cout << (a?a:m)-1 << endl;
	}
    return 0;
}