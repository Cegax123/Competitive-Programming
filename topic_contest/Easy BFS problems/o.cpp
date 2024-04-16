#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

const int INF = 1e9;
int n;
vector<pair<int, int>> adj[maxn];

bool comp(int x) {
    vector<bool> m1(n, 0), m2(n, 0);

    queue<int> q;
    q.push(0);
    m1[0] = 1;

    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(auto [to, c] : adj[v]) {
            if(m1[to]) continue;
            int w = c > x;

            if(w == 0) {
                if(!m1[to]) {
                    m1[to] = 1;
                    q.push(to);
                }
            }
        }
    }

    q.push(n-1);
    m2[n-1] = 1;

    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(auto [to, c] : adj[v]) {
            if(m2[to]) continue;
            int w = c > x;

            if(w == 0) {
                if(!m2[to]) {
                    m2[to] = 1;
                    q.push(to);
                }
            }
        }
    }

    if(m1[n-1]) return true;

    for(int i = 0; i < n; i++) {
        for(auto [to, w] : adj[i]) {
            if(m1[i] and m2[to]) return true;
        }
    }

    return false;
}

int main() {
    int m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    comp(7);

    int l = 0, r = 1e9;

    while(l < r) {
        int m = (l+r) >> 1;
        if(comp(m)) r = m;
        else l = m+1;
    }

    if(comp(l)) cout << l << "\n";
    else cout << -1 << "\n";

    return 0;
}
