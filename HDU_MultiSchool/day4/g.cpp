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

const int maxn = 20;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int ans = 0, a[maxn];
        rep0(i, 0, 16) {
            scanf("%d", &a[i]);
            if (!a[i]) ans += i / 4 + 1 + i % 4 + 1, a[i] = 16;
            rep1(j, 0, i) if (a[j] > a[i]) ans++;
        }
        if (ans & 1) puts("No");
        else puts("Yes");
    }
    return 0;
}