#include<bits/stdc++.h>
using namespace std;
int s[200],go[200];
vector<string>ans;
int check(int n){
	
 map<string,int>mp;
	string tmp="";
	for(int i=1;i<=n;i++){
		if(s[i]==1) tmp=tmp+'1';
		else tmp=tmp+'0';
	}
	string c0=tmp;
	mp[tmp]=1;
	for(int i=1;i<=2*n;i++){
		
		for(int j=1;j<=n;j++) go[j]=0;
		for(int j=1;j<=n;j++) {
			if(s[j]==1) go[j-1]++,go[j+1]++;
		}
		for(int j=1;j<n;j++){
			if(s[j]==1&&s[j+1]==1) go[j]=go[j+1]=0;
		}
		int tot=0;
		for(int j=1;j<=n;j++) if(go[j]>=2) go[j]=0;
	
	    tmp="";
		for(int j=1;j<=n;j++) s[j]=go[j],tot+=go[j];
		if(tot==0) break;
		for(int i=1;i<=n;i++){
			if(s[i]==1) tmp=tmp+'1';
			else tmp=tmp+'0';
		}
		mp[tmp]++;
		if(mp[tmp]>=2) {
			ans.push_back(c0);
			return 1;
		}
	}
	return 0;
}
int flag=0;
void dfs(int n,int len){
	//if(flag==1) return;
	if(n==len+1){
		int x=check(len);
		//if(x==1) flag=1;
		return ;
	}
	s[n]=1;
	//if(flag==1) return;
	dfs(n+1,len);
	s[n]=0;
	//if(flag==1) return;
	dfs(n+1,len);
}
int main(){
	/*int d;cin>>d;
	for(int i=1;i<=d;i++){
		ans.clear();
		flag=0;
		dfs(1,i);
		sort(ans.begin(),ans.end());
		for(auto x:ans){
			cout<<i<<" "<<x<<endl;
		}
	  }*/
	int n;
	cin>>n;
	if(n%2==0){
		for(int i=1;i<=n/2;i++){
			if(i%2==1) cout<<"10";
			else cout<<"01";
		}
	}
	else {
		if(n==3) cout<<"Unlucky"<<endl;
		else {
			cout<<"010";
			n-=3;
			for(int i=1;i<=n/2;i++){
				if(i%2==1) cout<<"10";
				else cout<<"01";
			}
		}
	}
}
