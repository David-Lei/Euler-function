#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<cstdlib>
#define MAXN 0x7fffffff
typedef long long LL;
const int N=10000500;
using namespace std;
inline LL Getint(){register LL x=0,f=1;register char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}return x*f;}
LL T,R;
LL cnt,prime[N];
bool vis[N];
LL inv[N],key[N];
LL n[N];
void Pre(){
	for(int i=2;i<N;i++){
		if(!vis[i])prime[++cnt]=i;
		for(int j=1;j<=cnt&&i*prime[j]<N;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}

	inv[1]=1;
	for(int i=2;i<N;i++)inv[i]=(R-R/i)*inv[R%i]%R;
	key[1]=1;
	for(int i=2;i<N;i++){
		key[i]=key[i-1];
		if(!vis[i])key[i]=((key[i]*(i-1))%R*inv[i]%R)%R;
	}

	n[1]=1;
	for(int i=2;i<N;i++)n[i]=(n[i-1]*i)%R;
}
int main(){
	T=Getint(),R=Getint();
	Pre();
	while(T--){
		LL x=Getint(),y=Getint();
		cout<<(n[x]*key[y])%R<<'\n';
	}
	return 0;
}
