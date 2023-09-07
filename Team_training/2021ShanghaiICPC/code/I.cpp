#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e2+10;
ll dp[2][6000][N];
int n,K;

void solve()
{
	cin>>n>>K;
	for(int i=0;i<=1;i++)
		for(int j=0;j<6000;j++)
			for(int k=0;k<N;k++)
				dp[i][j][k]=-1e18;
	
	dp[0][2600][0]=0;
	
	for(int i=1;i<=n;i++)
	{
		int v,t;
		cin>>v>>t;
		for(int j=0;j<=5200;j++)
		{
			for(int k=0;k<=K;k++)
			{
				dp[i&1][j][k]=dp[i&1^1][j][k];
				if(j>=t)dp[i&1][j][k]=max(dp[i&1^1][j-t][k]+v,dp[i&1][j][k]);
				if(j+t<=5200)dp[i&1][j][k]=max(dp[i&1^1][j+t][k]+v,dp[i&1][j][k]);
				if(j>=2*t&&k)dp[i&1][j][k]=max(dp[i&1^1][j-2*t][k-1]+v,dp[i&1][j][k]);
				if(j+2*t<=5200&&k)dp[i&1][j][k]=max(dp[i&1^1][j+2*t][k-1]+v,dp[i&1][j][k]);
			//	cout<<"db"<<endl;
			}
		}
	}
//	cout<<"db"<<endl;
	ll ans=-1e18;
	for(int i=0;i<=K;i++)
		ans=max(dp[n&1][2600][i],ans);
	cout<<ans<<endl;
} 

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--)
		solve();
}
