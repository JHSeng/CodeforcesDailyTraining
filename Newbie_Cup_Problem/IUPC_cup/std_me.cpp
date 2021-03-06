#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

const int maxn = 1e5 + 10;
int n, p = 0;
char s[maxn];
struct Node {
    int len;
    char c;
    Node() {}
    Node(int a, char b): len(a), c(b) {}
};
Node v[maxn];

int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    Node cnt{0, ' '};
    for (int i = 1; i <= n + 1; i++) {
        if (i == n + 1) {
            v[++p] = cnt;
            break;
        }
        if (i == 1) {
            cnt.len++, cnt.c = s[i];
            continue;
        }
        if (s[i] != cnt.c) {
            v[++p] = cnt;
            cnt.len = 1, cnt.c = s[i];
        } else cnt.len++;
    }
    int sum = 0;
    for (int i = 1; i <= p; i++)
        if (v[i].c == '1') sum += v[i].len;
    int ans = 0;
    for (int i = 1; i <= p; i++) {
        Node curr = v[i];
        if (curr.c == '1') {
            if (curr.len == sum) ans = max(ans, curr.len);
            else ans = max(ans, curr.len + 1);
        } else if (curr.len == 1 && i > 1 && i < n) {
            ans = max(ans, v[i - 1].len + v[i + 1].len);
            if (v[i - 1].len + v[i + 1].len < sum) ans = max(ans, v[i - 1].len + v[i + 1].len + 1);
        }
    }
    printf("%d\n", ans);
    return 0;
}