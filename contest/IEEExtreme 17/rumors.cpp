#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int main() {
    map<string, int> id;
    int cnt = 1;

    int n; cin >> n;
    vector<vector<pair<int, int>>> adj(2 * n);

    vector<bool> marked(n, 0);
    queue<int> q;

    for(int i = 0; i < n; i++) {
        string a, op, b; cin >> a >> op >> b;

        if(id[a] == 0) id[a] = cnt++;
        if(id[b] == 0) id[b] = cnt++;

        if(op == "->") {
            adj[id[a]].pb({id[b], 0});
            q.push(id[b]);
            marked[id[b]] = 1;
        }
        else {
            adj[id[a]].pb({id[b], 1});
            adj[id[b]].pb({id[a], 1});
        }
    }

    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(auto e : adj[v]) {
            int to = e.first, x = e.second;
            if(!marked[to] and x) {
                marked[to] = 1;
                q.push(to);
            }
        }
    }

    for(auto e : id) {
        if(!marked[e.second]) {
            cout << e.first << "\n";
        }
    }

    return 0;
}
