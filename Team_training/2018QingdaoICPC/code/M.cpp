#include<bits/stdc++.h>
using namespace std;
int v[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};

int f(int x){
	int res = 0;
	string s = to_string(x);
	for(auto c : s){
		int t = c - '0';
		res += v[t];
	}
	return res;
}
void solve(){
	int x, k;
	cin >> x >> k;
	
	int res = k, now = x;
	while(res > 0){
		if(!now){
			now = (res % 2);
			break;
		}
		now = f(now);
		-- res;
	}
	cout << now << endl;
}
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
