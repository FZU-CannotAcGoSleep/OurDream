#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,use[maxn];
vector<int>e[maxn];
typedef long long ll;
const ll mod=998244353;
ll pre[maxn];
ll ans=1;
void dfs(int u,int fa){
	
	int sz=0;
	for(auto to:e[u]){
		if(to==fa) continue;
		dfs(to,u);
		if(use[to]==1) sz++;
	}

	if(sz==0) {
		use[u]=1;
		return;
	}
	if(sz%2==0){
		use[u]=1;
		ll tmp=pre[sz-1];
		ans=ans*tmp%mod;
		//cout<<u<<" "<<tmp<<endl;
	}
	else {
		use[u]=0;
		if(sz>=3){
			ll tmp=sz*pre[sz-2]%mod;
			ans=ans*tmp%mod;
		  //  cout<<u<<" "<<tmp<<endl;
		}
		else {
			ans=ans*1%mod;
		}
	}
}
int main(){
	
	pre[1]=1;
	for(int i=3;i<maxn;i++)
		pre[i]=pre[i-2]*i%mod;
	
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	cout<<ans;
}
