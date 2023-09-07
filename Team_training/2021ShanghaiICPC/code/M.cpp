#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n%2==1){
		double a,b,c,val;
		a=n;
		b=(long long)(1.0*n+1)/2;
	    c=(long long)(1.0*n+1)/2;
		val=a*b*c;
		val=1/val;
		cout<<fixed<<setprecision(9)<<val;
	}
	else {
		double a,b,c,val;
		a=n;
		b=(long long)(1.0*n+1.0)/2;
		c=(long long)(1.0*n+2.0)/2;
		//cout<<a<<" "<<b<<" "<<c<<endl;
		val=a*b*c;
		val=1/val;
		cout<<fixed<<setprecision(9)<<val;
	}
}
