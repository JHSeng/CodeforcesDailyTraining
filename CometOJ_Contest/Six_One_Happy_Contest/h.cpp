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
#define lson curpos<<1
#define rson curpos<<1|1
/* namespace */
using namespace std;
/* header end */

int last = int_inf, dire = 1, n, ans = 0; //1 is down and 0 is up

int main() {
    cin >> n;
    while (n--) {
        int x; cin >> x;
        if (dire) {
            if (x >= last) {
                dire = 0;
                ans++;
            }
        } else if (x <= last)
            dire = 1;
        last = x;
    }
    printf("%d\n", ans);
    return 0;
}