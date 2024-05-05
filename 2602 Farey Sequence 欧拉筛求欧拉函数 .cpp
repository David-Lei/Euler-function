#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<cstdlib>
#define MAXN 0x7fffffff
typedef long long LL;
const int N=1000005;
using namespace std;
inline int Getint(){register int x=0,f=1;register char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}return x*f;}
LL ans[N];
int main(){
	for(int i=2;i<=1e6;i++)ans[i]=i;
    for(int i=2;i<=1e6;i++){
        if(ans[i]==i)
            for(int j=i;j<=1e6;j+=i)ans[j]=ans[j]/i*(i-1);
        ans[i]+=ans[i-1];
    }
    cout<<ans[2]<<'\n';
    while(1){
        int n=Getint();
        if(!n)return 0;
        cout<<ans[n]<<'\n';
    }
	return 0;
}
