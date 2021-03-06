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

const int maxn = 1e5 + 10;
struct Tree {
    int height, cost, number, index;
    void input() {
        scanf("%d%d%d", &height, &cost, &number);
    }
} tree[maxn];

bool cmp1(Tree n1, Tree n2) {
    return n1.cost < n2.cost;
}

bool cmp2(Tree n1, Tree n2) {
    return n1.height < n2.height;
}

struct Node {
    int l, r;
    ll num, sum = 0;
} segt[maxn * 3];

void maintain(int curpos) {
    if (segt[curpos].l == segt[curpos].r) return;
    segt[curpos].num = segt[curpos << 1].num + segt[curpos << 1 | 1].num;
    segt[curpos].sum = segt[curpos << 1].sum + segt[curpos << 1 | 1].sum;
}

void build(int curpos, int curl, int curr) {
    segt[curpos].l = curl; segt[curpos].r = curr;
    segt[curpos].num = segt[curpos].sum = 0;
    if (curl == curr) return;
    int mid = curl + curr >> 1;
    build(curpos << 1, curl, mid); build(curpos << 1 | 1, mid + 1, curr);
}

void add(int curpos, int index, int cost, int number) {
    if (segt[curpos].l == index && segt[curpos].r == index) {
        segt[curpos].num += number;
        segt[curpos].sum += (ll)cost * number;
        return;
    }
    int mid = segt[curpos].l + segt[curpos].r >> 1;
    if (index <= mid) add(curpos << 1, index, cost, number);
    else add(curpos << 1 | 1, index, cost, number);
    maintain(curpos);
}

ll query(int curpos, ll num) {
    if (num <= 0) return 0;
    if (num >= segt[curpos].num)
        return segt[curpos].sum;
    if (segt[curpos].l == segt[curpos].r)
        return segt[curpos].sum / segt[curpos].num * num;
    return query(curpos << 1, num) + query(curpos << 1 | 1, num - segt[curpos << 1].num);
}

int main() {
    int n;
    while (~scanf("%d", &n)) {
        ll ans = 0;
        rep0(i, 0, n) {
            tree[i].input();
            ans += (ll)tree[i].cost * tree[i].number; // calculate total cost
        }
        sort(tree, tree + n, cmp1); // sort by cost
        rep0(i, 0, n) tree[i].index = i + 1;
        build(1, 1, n); // build an empty tree
        sort(tree, tree + n, cmp2); // sort by height
        ll totNum = 0, numOfTallestTree = tree[0].number, res = ans - (ll)tree[0].number * tree[0].cost; // re num of tree
        int j = 0;
        rep1(i, 1, n) { // enum every tree as the tallest one
            if (i == n || tree[i].height != tree[i - 1].height) { // if the height is not equal
                ll tmp = query(1, totNum - numOfTallestTree + 1) + res;
                ans = min(ans, tmp);
                numOfTallestTree = tree[i].number;
                if (i < n)
                    while (j < i) {
                        add(1, tree[j].index, tree[j].cost, tree[j].number);
                        totNum += tree[j++].number;
                    }
            } else numOfTallestTree += tree[i].number;
            if (i < n) res -= (ll)tree[i].cost * tree[i].number;
        }
        printf("%lld\n", ans);
    }
    return 0;
}