#include <cstdio>
#define p 998244353
 
int main()
{
	int n,m,l,r; scanf("%d%d%d%d",&n,&m,&l,&r);
	long long x=r-l+1,k=n,sum=1; k=k*m;
	while(k>0)
	{
		if(k%2==1) sum=(sum*x)%p;
		x=(x*x)%p; k/=2;
	}
	if(n%2==0||m%2==0) if((r-l+1)%2==0)
		printf("%lld",(sum*499122177)%p);
	else printf("%lld",((sum*499122177)%p+499122177)%p);
	else printf("%lld",sum);
	return 0;
}