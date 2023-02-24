#include <bits/stdc++.h>

using namespace std;

#define int long long

#define _ 400007

int n;

int xx[_], yy[_];

int ans;

int tot;

struct abc {
    int x, y, dis;
} e[4000007];

int fa[_];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

bool cmp(abc a, abc b) {
    return a.dis < b.dis;
}

void kruskal() {
    sort(e + 1, e + tot + 1, cmp);
    for (int i = 1; i <= n; ++i) fa[i] = i;
    int kkk = 0;
    for (int i = 1; i <= tot; ++i) {
        int xx = find(e[i].x), yy = find(e[i].y);
        if (xx != yy) {
            fa[yy] = xx;
            kkk++;
            ans = max(ans, e[i].dis);
            if (kkk == n - 1) return;
        }
    }
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> xx[i] >> yy[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            int op = abs(xx[i] - xx[j]) + abs(yy[i] - yy[j]);
            e[++tot].x = i;
            e[tot].y = j;
            e[tot].dis = (op / 2) + (op & 1);
        }
    }
    for (int i=0;i<tot;i++) {
        printf("%ll %ll %ll\n", e[i].x,e[i].y,e[i].dis);
    }
    kruskal();
    cout << ans << "\n";
    return 0;
}