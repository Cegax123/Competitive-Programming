#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int P = 998244353;
int n, a[N], b[N];
vector <int> G[N];
bool vis[N];
int vertex, edge, self_loop;

void dfs(int x) {
    if (vis[x]) return ;
    vis[x] = true;
    vertex++;
    for (auto y : G[x]) {
        edge++;
        dfs(y);
        if (y == x) {
            self_loop++;
        }
    } 
}
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++) G[i].clear();
    for (int i = 1; i <= n; i++) {
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) vis[i] = false;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue ;
        vertex = 0;
        edge = 0;
        self_loop = 0;
        dfs(i);
        if (edge != 2 * vertex) {
            ans = 0;
        } else if (self_loop) {
            ans = 1ll * ans * n % P;
        } else {
            ans = ans * 2 % P;
        }
    }
    printf("%d\n", ans);
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve(); 
    }
    return 0; 
}
