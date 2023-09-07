#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N=1e5+5;
int n,a[N];
ll m;
ll temp[N];
bool check(ll x)
{
	for(int i=1;i<=n;i++)
		temp[i]=0;
	int cnt = m;
	for(int i=1;i<=n;i++)
	{
		if(temp[i] < x)
		{
			ll need = (x - temp[i] + a[i] - 1) / a[i];
			temp[i] += need * a[i];
			temp[i + 1] += (need - 1) * a[i + 1];
			cnt -= 2 * need - 1;
		}
		else
		{
			if(i == n) return true;
			-- cnt;
		}
		if(cnt < 0) return false;
	}
	return cnt >= 0;
} 

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ll l=0,r=1e17;
	while(l<r)
	{
		ll mid=l+r+1>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}  
	cout<<l<<endl;
}
signed  main(){
	//freopen("lys.in","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
