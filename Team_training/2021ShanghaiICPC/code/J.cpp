#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
int sum[N],id[N];
bool cmp(int x,int y){
	if(sum[x]==sum[y]) return x<y;
	else return sum[x]>sum[y];
}
char s[N],b[N];
void solve( ){
	int n;
	cin>>n;
	cin>>(s+1);
	cin>>(b+1);
	sum[0]=0;
	id[0]=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='1') sum[i]=sum[i-1]+1;
		else sum[i]=sum[i-1]-1;
		id[i]=i;
	}
	sort(id,id+n+1,cmp);
	
	bitset<N+1>one,A,ans;
	for(int i=1;i<=n;i++) one[i]=1,A[i]=0,ans[i]=0;
	
	int limit=n+1;
	for(int i=0;i<=n;i++){
		int pos=id[i];
		//cout<<i<<" # "<<ans<<endl;
		if(pos){
			if(b[pos]=='1') { // 要求 num_1 > num_0
				ans= ans | (A>>(n-pos));
				if(sum[pos]<=0) limit=min(limit,pos+1);
			}
			else {
				ans= ans | ( (A^one)>>(n-pos) );
				if(sum[pos]>0 ) limit=min(limit,pos+1);
			}
			//	cout<<i<<" # "<<(A>>(n-pos))<<" "<<ans<<endl;
		}
		A[n-pos]=1;// 访问过,打个标儿
	}
	
	for(int i=1;i<=n;i++){
		if(ans[i]||i>=limit) cout<<0;
		else cout<<1;
	}
	cout<<endl;
}
int main(){
	//	freopen("lys.in","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve( );
	}
}
