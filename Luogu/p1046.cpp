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

int a[10], h;

int main() {
    for (int i = 0; i < 10; i++) scanf("%d", &a[i]);
    scanf("%d", &h); h += 30;
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        if (a[i] <= h) ans++;
    }
    printf("%d\n", ans);
    return 0;
}