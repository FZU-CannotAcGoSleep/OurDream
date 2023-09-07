#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
typedef long long ll;
int n,m,q,cnt;
ll val[maxn],a[maxn];
struct edge{
	int u,v,w;
}e[maxn];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
struct dsu{
	int fa[maxn];
	void build( ){
		for(int i=1;i<=n;i++) fa[i]=i;
	}
	int find(int x){
		if(fa[x]!=x) return fa[x]=find(fa[x]);
		else return x;
	}
}dsu;
vector<int>v[maxn];
int f[maxn][22];
void dfs(int u,int fa){
	//cout<<u<<" "<<fa<<endl;
	f[u][0]=fa;
	for(int i=1;i<21;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(auto to:v[u]){
		if(to==fa) continue;
		dfs(to,u);
		a[u]+=a[to];
	}
	//cout<<u<<" val[u] "<<val[u]<<endl;
}
void kruscal(){
	sort(e+1,e+m+1,cmp);
	dsu.build();
	cnt=n;
	for(int i=1;i<=m;i++){
		int f1=dsu.find(e[i].u),f2=dsu.find(e[i].v);
		if(f1==f2) continue;
		cnt++;
        val[cnt]=e[i].w;
		dsu.fa[f1]=dsu.fa[f2]=dsu.fa[cnt]=cnt;
		v[cnt].push_back(f1);v[f1].push_back(cnt);
		v[cnt].push_back(f2);v[f2].push_back(cnt);
		if(cnt==n+n-1) break;
	}
	dfs(cnt,0);
}
int main(){
	
	//freopen("lys.in","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	
	kruscal();
	while(q--){
		int x; ll y;
		cin>>x>>y;
		int at=x;
		ll ans=a[x]+y;
		while(at!=cnt){
			int jump=0;
			for(int i=20;i>=0;i--){
				if(f[at][i]&&val[f[at][i]]<=ans){
				//	cout<<at<<" to "<<f[at][i]<<" "<<ans<<endl;
					at=f[at][i];
					ans=a[at]+y;
				    jump=1;
				}
			}
			if(!jump) break;
		}
		cout<<ans<<endl;
	}
}
