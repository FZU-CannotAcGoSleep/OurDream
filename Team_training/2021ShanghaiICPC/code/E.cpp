
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, k;
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> k;
	vector<int> a(n);
	for(auto &i : a) cin >> i;
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	int ans = 1;
	n = a.size();
	
	int x = a[0];
	for(int i = 1; i < n; ++i){
		if(a[i] - x >= k) ++ ans, x = a[i];
	}
	cout << ans << endl;
	return 0;
}
