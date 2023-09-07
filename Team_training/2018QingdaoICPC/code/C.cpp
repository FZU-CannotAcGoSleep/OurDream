#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
char s[maxn],t[maxn];
int sum[maxn],f[maxn];
typedef long long ll;
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i],f[i]=0;
	for(int j=1;j<=n;j++) cin>>t[j];
	
	if(n==1){
		if(s[1]==t[1]) cout<<1<<endl;
		else cout<<0<<endl;
		return;
	}
	int flag=0;
	for(int i=1;i<=n;i++) if(s[i]!=t[i]) f[i]=1,flag=1;
	if(flag==0){
		ll ans=(ll)n;
		cout<<ans*(ans+1)/2<<endl;
		return ;
	}
	f[0]=0;
	
	int cnt=0;
	ll mxlen=-1;
	f[n+1]=0;
	ll p[5];
	memset(p,0,sizeof p);
	for(int i=1;i<=n; ){

		if(f[i]==0) {
			i++;
			continue;
		}
		else {
			int at=i;
			cnt++;
			while(f[i]==1) {
			  i++;
			 // cout<<i<<" ";
			}
		//	cout<<endl;
			p[cnt]=i-at;
			mxlen=max(mxlen,(ll)i-at);
		}
	}
	//cout<<cnt<<" "<<mxlen<<endl;
	
	if(cnt==2) {
		cout<<6<<endl;
	}
	else if(cnt==1){
		cout<<(mxlen-1)*2+(n-mxlen)*2<<endl;
	}
	else cout<<0<<endl;
}
int  main(){
	//freopen("lys.in","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
