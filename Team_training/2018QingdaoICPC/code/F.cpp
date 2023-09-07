#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int a[maxn];
int lowbit(int x){
	return x&(-x);
}
void pr(int n){
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<endl;
}
void solve(){
	int n,k,tt;
	cin>>n>>k;
	int cnt=0;
	tt=n;
	while(tt%2==0&&tt){
		cnt++;
		tt/=2;
	}
	if(k>pow(2,cnt)-1) {
		cout<<"Impossible"<<endl;
		return ;
	}
	for(int i=1;i<=n;i++) a[i]=i;
	
	for(int i=1;i<=k;i++){
	
		int len=lowbit(i)*2;
		//cout<<i<<" # "<<len<<endl;
		for(int j=1;j<=n;j+=len){
			
			int l=j,r=j+len-1;
		//	cout<<l<<" "<<r<<endl;
			for(;;l++,r--) {
			    if(l>r) break;
				swap(a[l],a[r]);
			//	cout<<l<<" "<<r<<endl;
			}
		}
			pr(n);
	}
}
int main(){
//	freopen("lys.in","r",stdin);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
