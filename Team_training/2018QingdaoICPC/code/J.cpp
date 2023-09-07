#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int a[N];
int n,k;
int suf[N];
void solve(){
	cin>>n>>k;
	int temp=0; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)temp++;
	}
	if(n==k)
	{
		cout<<"Richman"<<endl;
		return;
	}
	k-=temp;
	if(k<0)
	{
		cout<<"Impossible"<<endl;
		return;
	}
	suf[n+1]=1e9;
	for(int i=n;i>=1;i--)
	{
		if(a[i]!=0)suf[i]=min(suf[i+1],a[i]);
		else suf[i]=suf[i+1];
	}
	ll sum=0;
	for(int i=1;i<=k;i++)
	{
		if(a[i]==0)
		{
			k++;
			continue;
		}
		sum+=a[i];
	}
	sum+=suf[k+1]-1;
	cout<<sum<<endl;
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
