/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn=110;
int n,a[maxn],vis[maxn],ans=0;

int check(){
	for (int i=1;i<=n;i++) 
		if (!vis[i]) return i;
	return -1;
}

int main() {
	scanf("%d",&n);
	rep1(i,1,n) scanf("%d",&a[i]);
	rep1(i,1,n) vis[i]=0;
	sot(a,n);
	int cnt=0;
	while (1){
		int pos=check();
		if (pos==-1) break;
		ans++;
		vis[pos]=1;
		for (int i=pos;i<=n;i++)
			if (!vis[i] && a[i]%a[pos]==0) vis[i]=1;
	}
	printf("%d\n",ans);
    return 0;
}
