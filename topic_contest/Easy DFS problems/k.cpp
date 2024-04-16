#include<bits/stdc++.h>
using namespace std;

const int E = 26;
int v[E];
bool vis[E];

void dfs(int l) {
    vis[l] = 1;

    for(int nxt = 0; nxt < E; nxt++) {
        if(vis[nxt]) continue;

        for(int j = 0; j < E; j++) {
            int has = (v[l]>>j)&1;
            int other = (v[nxt]>>j)&1;

            if(has and other) {
                dfs(nxt);
            }
        }
    }
}

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        int curr = 0;

        for(char c : s) {
            int d = c-'a';
            curr |= (1 << d);
        }

        for(char c : s) {
            v[c-'a'] |= curr;
        }
    }

    int cnt = 0;
    for(int i = 0; i < E; i++) {
        if(!vis[i] and v[i]) {
            dfs(i);
            cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}
