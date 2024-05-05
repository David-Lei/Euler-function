#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<cstdlib>
#define MAXN 0x7fffffff
typedef long long LL;
const int N=10005;
using namespace std;
inline int Getint(){register int x=0,f=1;register char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int euler(int m){
	int ans=m;
	for(int i=2;i*i<=m;i++){
		if(m%i==0){
			ans=ans/i*(i-1);
			while(m%i==0)m/=i;
		}
	}
	if(m>1)ans=ans/m*(m-1);
	return ans;
}
int main(){
	int n;
	while(~scanf("%d",&n))cout<<euler(n-1)<<'\n';
	return 0;
}