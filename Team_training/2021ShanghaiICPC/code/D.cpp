#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
	int p,q;
	cin>>p>>q;
	int d=__gcd(p,q);
	p=p/d,q=q/d;
	for(int i=1;i*i<=q;i++)
	{
		if(q%i==0)
		{
			int a=i,b=q/i;
			if(a*a+b*b==p)
			{
				cout<<a<<' '<<b<<endl;
				return;
			}
		}
	}
	cout<<0<<' '<<0<<endl;
 } 

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	cin>>T;
	while(T--)
		solve();
}
