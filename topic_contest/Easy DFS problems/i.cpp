#include<bits/stdc++.h>
using namespace std;

const int maxn = 305;
vector<int> adj[maxn];
bool vis[maxn];
vector<int> curr;

void dfs(int v) {
    vis[v] = 1;
    curr.push_back(v);

    for(int to : adj[v]) if(!vis[to]) {
        dfs(to);
    }
}

int main() {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char c; cin >> c;
            if(c == '1') {
                adj[i].push_back(j);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        curr.clear();
        if(!vis[i]) dfs(i);

        vector<int> el;
        for(int x : curr) el.push_back(a[x]);
        sort(el.begin(), el.end());
        sort(curr.begin(), curr.end());

        for(int i = 0; i < (int) el.size(); i++) {
            a[curr[i]] = el[i];
        }
    }

    for(int i = 0; i < n; i++) cout << a[i] << " ";

    return 0;
}
