#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define eps 1e-8
#define int_inf (1<<30)-1
#define ll_inf (1LL<<62)-1
#define lson curPos<<1
#define rson curPos<<1|1

using namespace std;

const int maxn=20;
int n,a[maxn],flag=0;

void dfs(int times,int sum){
    if (n==times){
        if (sum%360==0) flag=1;
        return;
    }
    dfs(times+1,sum+a[times]);
    dfs(times+1,sum-a[times]);
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    dfs(0,0);
    if (flag) puts("YES"); 
        else puts("NO");
    return 0;
}
