#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

class DisjointSet {
  std::vector<int> p;

public:
  DisjointSet(int n)
  : p(n, -1) { }

  int root(int x) {
    return p[x] < 0 ? x : p[x] = root(p[x]);
  }

  bool unite(int x, int y) {
#ifndef NDEBUG
    int n = p.size();
    assert(x >= 0 && x < n);
    assert(y >= 0 && y < n);
#endif // NDEBUG
    if ((x = root(x)) != (y = root(y))) {
      int& rx = p[x];
      int& ry = p[y];
      if (rx == ry) {
        --rx, ry = x;
      } else {
        rx < ry ? ry = x : rx = y;
      }
      return true;
    }
    return false;
  }
};

const int maxn = 8e5 + 5;
vector<int> adj[maxn];

bool vis[maxn];

void dfs(int v) {
  vis[v] = 1;
  for(int to : adj[v]) {
    if(!vis[to]) dfs(to);
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int m; cin >> m;
  vector<tuple<int, int, int, int>> edges(m);
  map<string, int> id;
  int n = 1;

  for (int i = 0; i < m; ++i) {
      string a, b; cin >> a >> b;
      int w; cin >> w;

      if(id[a] == 0) id[a] = n++;
      if(id[b] == 0) id[b] = n++;

      edges[i] = {id[a], id[b], w, i};
      adj[id[a]].push_back(id[b]);
      adj[id[b]].push_back(id[a]);
  }

  int cnt = 0;
  for(int i = 1; i < n; i++) {
    if(!vis[i]) {
      dfs(i);
      cnt++;
    }
  }

  if(cnt > 1) {
    cout << "-1\n";
    return 0;
  }

  sort(edges.begin(), edges.end(), [](const auto& lhs, const auto& rhs) {
    return get<2>(lhs) < get<2>(rhs);
  });
  vector<string> answers(m, "at least one");
  DisjointSet dsu(n+1);
  for (int i = 0, j = 0; i < m; i = j) {
    int w = get<2>(edges[i]);
    while (j < m && get<2>(edges[j]) == w) {
      j++;
    }
    
    unordered_map<int, vector<pair<int, int>>> g;
    for (int k = i; k < j; ++k) {
      auto [u, v, w, id] = edges[k];
      u = dsu.root(u);
      v = dsu.root(v);
      if (u == v) {
        answers[id] = "none";
      } else {
        g[u].emplace_back(v, id);
        g[v].emplace_back(u, id);
      }
    }

    unordered_map<int, int> num, low;
    unordered_set<int> erased;
    int cnt = 0;
    function<void(int)> dfs = [&](int u) {
      num[u] = low[u] = ++cnt;
      for (auto [v, id] : g[u]) {
        if (!erased.count(id)) {
          erased.insert(id);
          if (!num.count(v)) {
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= num[v]) {
              answers[id] = "any";
            }
          } else {
            low[u] = min(low[u], num[v]);
          }
        }
      }
    };
    for (auto& adj : g) {
      int v = adj.first;
      if (num[v] == 0) {
        dfs(v);
      }
    }

    for (int k = i; k < j; ++k) {
      auto [u, v, w, id] = edges[k];
      dsu.unite(u, v);
    }
  }

  ll ans = 0;
  for(int i = 0; i < m; i++) {
      if(answers[i] == "any" or answers[i] == "at least one") ans += get<2>(edges[i]);
  }

  cout << ans << "\n";

  return 0;
}
